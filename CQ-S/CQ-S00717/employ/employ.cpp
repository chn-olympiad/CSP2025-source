#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ans=0;
char a[10000000];
int c[10000000];
int p[10000000]={0};
int v[10000000]={0};
ll mod=998244353;
void dfs(int k){
	if(k>n){
		int gou=0;
		int zai=n;
		for(int i=1;i<=n;i++){
			if(gou>=c[p[i]]){
				gou+=1;
				zai-=1; 
			}
			else if(a[i-1]=='0'){
				gou+=1;
				zai-=1;
			}
			if(zai<m){
				return ;
			}
		}
		ans+=1;
		ans=ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			p[k]=i;
			v[i]=1;
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int w=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			w+=1;
		}
	}
	int f=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]!='1'){
			f=0;
			break;
		}
	}
	if(f){
		ans=1;
		for(ll i=1;i<=n;i++){
			ans=ans*i;
			ans=ans%mod;
		}
		cout<<ans;
		return 0;
	}	
	dfs(1);
	cout<<ans;
	return 0;
} 
