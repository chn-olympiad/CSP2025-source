#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,q,L[200005],id,j[200005],k[200005];
const ull p=1331;
ull P[5000005];
ull c[200005],d[200005],c1[200005],d1[200005],C[5000005],D[5000005];
char s[5000005],t[5000005];
map<pair<ull,ull>,int>mp;
vector<int>v[200005];
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
	P[0]=1;
	for(int i=1;i<=5000000;i++)P[i]=P[i-1]*p;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);
		L[i]=strlen(s+1);
		j[i]=1,k[i]=L[i];
		for(;j[i]<=L[i];j[i]++){
			if(s[j[i]]!=t[j[i]])break;
		}
		for(;k[i]>=j[i];k[i]--){
			if(s[k[i]]!=t[k[i]])break;
		}
		if(j[i]>k[i])continue;
		for(int g=k[i];g>=j[i];g--){
			c[i]=c[i]*p+s[g];
			d[i]=d[i]*p+t[g];
		}
		for(int g=L[i];g;g--){
			c1[i]=c1[i]*p+s[g];
			d1[i]=d1[i]*p+t[g];
		}
		if(mp.count(make_pair(c[i],d[i])))v[mp[make_pair(c[i],d[i])]].emplace_back(i);
		else{
			id++;
			mp[make_pair(c[i],d[i])]=id;
			v[id].emplace_back(i);
		}
	}
	for(int Q=1;Q<=q;Q++){
		scanf("%s%s",s+1,t+1);
		int len=strlen(s+1),l=1,r;r=len;
		for(;l<=len;l++){
			if(s[l]!=t[l])break;
		}
		for(;r>=l;r--){
			if(s[r]!=t[r])break;
		}
		if(l>r)continue;
		c[0]=d[0]=0;
		for(int g=r;g>=l;g--){
			c[0]=c[0]*p+s[g];
			d[0]=d[0]*p+t[g];
		}
		C[len+1]=D[len+1]=0;
		for(int g=len;g;g--){
			C[g]=C[g+1]*p+s[g];
			D[g]=D[g+1]*p+t[g];
		}
		int an=0;
		if(mp.count(make_pair(c[0],d[0]))){
			int id=mp[make_pair(c[0],d[0])];
			for(int i:v[id]){
				int x=l-j[i]+1,y=r+(L[i]-k[i]);
				if(x<1||y>len)continue;
				ull t1=c1[i],t2=(C[x]-C[y+1]*P[y-x+1]);
				if(t1!=t2)continue;
				t1=d1[i],t2=(D[x]-D[y+1]*P[y-x+1]);
				if(t1!=t2)continue;
				an++;
			}
		}
		printf("%d\n",an);
	}
	return 0;
}
