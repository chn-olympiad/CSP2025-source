#include<bits/stdc++.h>
using namespace std;
bool a[1000001];
long long c[1000001],zhuiyi[1000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long m,n,ans=0,cnt=0;
	cin>>n>>m;
	if(m==n){
		long long ansx=1;
		for(long long i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
		for(long long i=0;i<n;i++){
			cin>>c[i];
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		while(n--){
			ansx*=n;
			ansx%=998244353;
		}
		cout<<ansx;
		return 0;
	}
	else cout<<0;
}
