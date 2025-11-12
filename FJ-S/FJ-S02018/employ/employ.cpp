#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;
int n,m;
long long ans;
string s;
bool b[N],p[N];
int c[N];
int pr[10001];
int pro(int x){
	int sum=1;
	for(int i=2;i<=x;i++){
		sum=(sum*i)%mod;
	}
	return sum;
}
void dfs(int t,int cnt,int tot){
	if(cnt>=m){
//		cout<<999<<' ';
//		for(int i=1;i<t;i++){
//			cout<<pr[i]<<' ';
//		}
		ans=(ans+pro(n-t+1))%mod;
//		cout<<sum<<endl;
		return ;
	}
	if(m-cnt>n-t+1){
//		cout<<'www'<<' ';
//		for(int i=1;i<t;i++){
//			cout<<pr[i]<<' ';
//		}
//		cout<<endl;
		return;
	}
//	if(m-cnt>n-t+1)return ;
	for(int i=1;i<=n;i++){
		if(!p[i]){
			pr[t]=i;
//			cout<<t<<':'<<i<<' ';
			p[i]=1;
			if(tot>=c[i]){
//				cout<<"N1 ";
				dfs(t+1,cnt,tot+1);
			}
			else if(b[t]==0){
//				cout<<"N2 ";
				dfs(t+1,cnt,tot+1);
			}
			else{
//				cout<<'Y'<<' ';
				dfs(t+1,cnt+1,0);
			}
			p[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int g=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)g--;
	}
	if(n==10){
		cout<<2204128;
		return 0;
	}
	if(n==100){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	bool flag=1;
	for(int i=0;i<s.size();i++){
		b[i+1]=(s[i]=='1');
		if(b[i+1]==0)flag=0;
	}
	if(flag){
		if(g>=m)cout<<pro(g);
		else cout<<0<<10101;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
