/*
*/
#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define MOD 998244353
#define N 505
#define ll long long
using namespace std;
int n,m;
string s;
int c[N];
bool f=false;
int high[N];
ll ans;
bool vis[N];
int p[N];
void dfs(int x){
	if(x==n+1){
		int cnt=0,k=0;
		for(int i=1;i<=n;i++){
			if(k>=c[p[i]]){
				k++;
			}else{
				if(high[i]){
					cnt++;
				}else{
					k++;
				}
			}
		}
		if(cnt>=m){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
	return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	in(n),in(m);
	cin>>s;
	for(int i=0;i<s.size();i++){
		high[i+1]=s[i]-'0';
		if(high[i+1]==0) f=true;
	}
	int t=n;
	for(int i=1;i<=n;i++){
		in(c[i]);
		if(!f){
            if(c[i]==0) t--;
		}
	}
    if(!f){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=MOD;
        }
        ll s=1;
        for(int k=n;k>=n-m+2;k--){
            s*=k;
            s%=MOD;
        }
        cout<<ans-s;
        return 0;
    }
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
    return 0;
}
