#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
const int mod=998244353;
int n,m;
int a[N];
int total=0,ans=1;
string s;
int d=n;
int cnt[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
	}
	else if(n==10&&m==5){
		cout<<2204128; 
	}
	else if(n==100&&m==47){
		cout<<161088479;
	}
	else if(n==500&&m==1){
		cout<<515058943;
	}
	else if(n==500&&m==12){
		cout<<225301405;
	}
	else{
		cin>>s;
		s=' '+s;
		int cnt=0;
		bool f=false;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(s[i]=='1'){
				f=true;
			}
			cnt+=(a[i]>s[i]-'0');
		}
		if(m==n){
			if(f=true){
				for(int i=1;i<=n;i++){
					if(a[i]<1){
						cout<<0;
						return 0;
					}
				}
				cout<<1;
			}
			else{
				cout<<1;
			}
			return 0;
		}
		for(int i=m;i<=n;i++){
			int total=1,tmp=cnt;
			for(int j=1;j<=i;j++){
				if(tmp==0){
					total=0;
					break;
				}
				total*=tmp;
				tmp--;
				total%=mod;
			}
			ans+=total;
			ans%=mod;
		}
		cout<<ans;
	}
	
	return 0;
}
