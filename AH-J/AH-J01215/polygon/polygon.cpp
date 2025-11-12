#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define int ll
const int mod=998244353;
const int N=5e3+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
int a[N]={};
int sum[N]={};
int C[N][N]={};
void init(){
	for(int i=1;i<=5000;i++){
		C[i][1]=i;
		C[i][i]=1;
		for(int j=2;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	IO;
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else{
		if(a[n]==0){
			cout<<0<<endl;
		}else if(a[n]==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}
			}
			int cnt1=n-cnt;
			int sum=0;
			for(int i=2;i<=cnt;i++){
				sum=(sum+C[cnt][i])%mod;
			}
			sum=(sum*cnt1)%mod;
			cout<<sum<<endl;
		}
	}
	return 0;
}
