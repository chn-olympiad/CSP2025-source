#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500+10,mod=998244353;
ll n,m,a[N],x[N],p=0,ans=0;
char s[N];
bool vis[N];
bool specialA=1;
bool check(){
	int c=0,res=0;
	for(int i=1;i<=n;i++){
		if(c>=a[x[i]]||s[i]=='0')
			c++;
		else
			res++;
	}
	return res>=m;
}
void work(int k){
	if(k>n){
		if(check())
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			x[k]=i;
			work(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			p++;
	}
	if(n-p<m){
		cout<<0;
		return 0;
	}
	work(1);
	cout<<ans;
	return 0;
}
