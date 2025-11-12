#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=998244353;
ll ans=1;
int n,m;
int p[1111];
char a[11111];
int die;
bool ck(string u){
	die=0;
	for(int i=0;i<n;i++){
		if(p[u[i]-'0']<=die||a[i]=='0'){
			die++;
		}
	}
	if(n-die>=m){
		return 1;
	}
	return 0;
}
bool us[1000];
int sum;
void dfs(int x,string q){
	if(x==n+1){
		if(ck(q)) sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!us[i]){
			us[i]=1;
			dfs(x+1,q+char(i+48));
			us[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool ok=1;
	scanf("%s",a);
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			ok=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	if(ok){
		for(ll i=1;i<=(ll)(n);i++){
			ans*=i;
			ans%=M;
		}
		cout<<ans;
	}else{
		dfs(1,""); cout<<sum%M;
	}
	return 0;
}
