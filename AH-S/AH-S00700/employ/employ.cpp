#include<bits/stdc++.h>
#define N 505
#define MOD 998244353
#define ll long long
using namespace std;
string s;
int n,m,flag=1,c[N];
void afs(){
	if(flag==0) {cout<<0;return;}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			cout<<0;return;
		}
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
}
void sdk(){
	ll ans=1,cnt=0;
	for(int i=1;i<=n;i++)
		if(c[i]!=0) cnt++;
	if(cnt<m) {cout<<0;return;}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
		cout<<ans<<endl;
	}
	cout<<ans;
}
int vis[20],cc[20];
ll ans=0;
void check(){
	int win=0,lose=0;
	for(int i=1;i<=n;i++){
		if(lose>=c[cc[i]]||s[i]=='0') lose++;
		else win++;
		if(win>=m){
			ans++;
			return;
		}
	}
}
void baosou(int x){
	if(x>n) check();
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			cc[x]=i;
			baosou(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]=='0') flag=0;
	if(m==n) {afs();return 0;}
	if(flag==1) {sdk();return 0;}
	baosou(1);
	cout<<ans%MOD;
	return 0;
}
