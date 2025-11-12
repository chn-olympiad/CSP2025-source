#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,flagB=1,u[200010],v[200010];
int tong1[5000010],tong2[5000010];
map<string,int>s;
string s1,s2,t1,t2;
signed main(){
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		if(s[s1]!=0&&s[s1]==s[s2])continue;
		s[s1]=i;s[s2]=i;
		int l=s1.size(),cnta=0,cntb=0;
		for(int j=0;j<l;j++){
			if(s1[j]=='a')cnta++;
			if(s1[j]=='b')cntb++,u[i]=j;
		}
		if(cnta!=l-1||cntb!=1)flagB=0;
		cnta=0,cntb=0;
		for(int j=0;j<l;j++){
			if(s2[j]=='a')cnta++;
			if(s2[j]=='b')cntb++,v[i]=j;
		}
		if(cnta!=l-1||cntb!=1)flagB=0;
		if(v[i]>=u[i])tong1[v[i]-u[i]]++;
		else tong2[u[i]-v[i]]++;
	}
//	cout<<flagB<<endl;
	while(m--){
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size(),cnta=0,cntb=0;
		if(l1!=l2){
			cout<<"0\n";
			continue;
		}
		int x,y;
		for(int i=0;i<l1;i++){
			if(t1[i]=='a')cnta++;
			if(t1[i]=='b')cntb++,x=i;
		}
		if(cnta!=l1-1||cntb!=1)flagB=0;
		cnta=0,cntb=0;
		for(int i=0;i<l2;i++){
			if(t2[i]=='a')cnta++;
			if(t2[i]=='b')cntb++,y=i;
		}
		if(cnta!=l2-1||cntb!=1)flagB=0;
		if(flagB){
			if(y-x>=0){
				cout<<tong1[y-x]<<endl;
				continue;
			}else{
				cout<<tong2[x-y]<<endl;
				continue;
			}
		}
	}
	return 0;
}


