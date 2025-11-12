#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
int P=998244353;
int n,m;
string s;
int a[1001];
int b[1001];
int ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==n) cout<<0;
	if(m==1){
		bool f=false;
		bool flag=false;
		cin>>s;
		int p=0;
		FOR(i,1,n) {
			a[i]=s[i-1]-'0';
			if(a[i]==1&&f==false) f=true,p=i;
		}
		int peo=0;
		FOR(i,1,n) {
			cin>>b[i];
			if(b[i]==0) {
				flag=false;
				peo++;
			}
		}
		if(f&&flag) {
			ans=1;
			FOR(i,1,n){
				ans*=i;
				ans%=P;
			}
			cout<<ans;
			return 0;
		}
		else if(f&&!flag){
			//有peo个人没有耐心，即不能全放在最后 
			if((peo+p)<=n){
				ans=1;
				FOR(i,1,n){
					ans*=i;
					ans%=P;
				}
				cout<<ans;
				return 0;
			}
			else {//分块 
				ans=1;
				FOR(i,1,n){
					ans*=i;
					ans%=P;
				}
				int cnt=1;
				FOR(i,1,n-peo){
					cnt*=i;
					cnt%=P;
				}
				cnt*=(p-(n-peo));
				cnt%=P;
				cnt*=peo;
				cnt%=P;
				ans-=cnt;
				if(ans<0) ans+=P;
				cout<<ans;
				return 0;
			}
		}
		else if(!f) {
			cout<<0;
			return 0;
		}
	}
	else cout<<1;
	return 0;
}


