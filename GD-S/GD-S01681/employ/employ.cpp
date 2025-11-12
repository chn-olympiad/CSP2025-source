#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const ll mod=998244353;
int n,m,c[N];
ll ans;
bool fl;
bool v[N];
char s[N];
void dfs(int k,int wl,int ly){
	if(k==n+1){
		if(ly>=m) ans++;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!v[i]){
				v[i]=1;
				if(s[k]=='0') dfs(k+1,wl+1,ly);
				else if(c[i]<=wl) dfs(k+1,wl+1,ly);
				else{
					dfs(k+1,wl,ly+1);
				}
				v[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') fl=1; 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(!fl){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%
