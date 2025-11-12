#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+10,M=5e6+10;
struct node{
	ll h1,h2;
	int len;
}a[M];
ll p[M],h1[M];
string s1,s2,t1,t2;
pair<int,int> b[N];
unordered_map<int,vector<int>> mp;
ll gt(int l,int r){
	if(!l)return h1[r];
	return h1[r]-h1[l-1]*p[r-l+1];
}
void solve(int n,int _){
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;s1[j];j++){
			a[i].h1=a[i].h1*137+s1[j];
			a[i].h2=a[i].h2*137+s2[j];
		}
		a[i].len=s1.size();
		int b1,b2;
		for(int j=0;s1[j];j++){
			if(s1[j]=='b')b1=j;
			if(s2[j]=='b')b2=j;
		}
		b[i]={b1,b1-b2};
		mp[b1-b2].push_back(i);
	}
	while(_--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int b1,b2,len=t1.size();
		for(int i=0;t1[i];i++){
			if(t1[i]=='b')b1=i;
			if(t2[i]=='b')b2=i;
		}
		int ans=0;
		for(int i:mp[b1-b2]){
			if(b[i].first<=b1&&a[i].len<=len&&b1-b[i].first+a[i].len<=len)ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,_;
	scanf("%d%d",&n,&_);
	if(n>100){
		solve(n,_);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;s1[j];j++){
			a[i].h1=a[i].h1*137+s1[j];
			a[i].h2=a[i].h2*137+s2[j];
		}
		a[i].len=s1.size();
	}
	p[0]=1;
	for(int i=1;i<=5e6;i++)p[i]=p[i-1]*137;
	while(_--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int len1=t1.size();
		ll h2=0;
		for(int i=0;t2[i];i++){
			h2=h2*137+t2[i];
		}
		h1[0]=t1[0];
		for(int i=1;t1[i];i++){
			h1[i]=h1[i-1]*137+t1[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<len1-a[i].len+1;j++){
				if(gt(j,j+a[i].len-1)==a[i].h1){
					if(!j){
						if(a[i].h2*p[len1-a[i].len]+gt(a[i].len,len1-1)==h2)ans++;
					}else{
						if(h1[j-1]*p[len1-j]+a[i].h2*p[len1-j-a[i].len]+gt(j+a[i].len,len1-1)==h2)ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
