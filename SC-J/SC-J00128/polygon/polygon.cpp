#include<bits/stdc++.h>
using namespace std;
const int N=5030;
long long a[N];
int n;
long long ans;
const int MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long cnt=a[i];
		long long maxx=a[i];
		long long b=2*a[i];
		for(int j=i+1;j<=n;j++){
			cnt+=a[j];
			maxx=max(maxx,a[j]);
			b=2*maxx;
			if(j-i>=2){
			if(cnt>b){
			//	cout<<"cnt"<<cnt<<"\n";
				ans++;
			}
		}
		}
	}
	cout<<ans%MOD;
	return 0;
}