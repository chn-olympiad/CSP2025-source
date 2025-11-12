#include <bits/stdc++.h>
using namespace std;

const long long M = 998244353;

int n;
int a[5005],qz[5005];
int ans;
int maxn;
int maxt;
long long t = 1;
//stack <int> stk;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		maxt = max(maxt,a[i]);
	}
	if(n == 3){
		int sum  = 0;
		for(int i = 1;i <= n;i++){
			sum += a[i];
			maxn = max(a[i],maxn);
		}
		if(sum > 2*maxn){
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(maxt == 1){
		for(int i = 3;i <= n;i++){
			t = 1;
			for(int j = i+1;j <= n;j++){
				t = t*j;
				t %= M;
//				printf("%d %d\n",j,t);
			}
			for(int j = 2;j <= n-i;j++){
				t/=j;
//				cout<<t<<' '<<j;
			}
			ans+=t;
//			cout<<t<<endl;
		}
		cout<<ans;
	}
//	long long sum = 0;
//	for(int len = 3;len <= n;len++){
//		for(int i = 1;i <= n-len+1;i++){
//			stk.push(a[i]);
//			sum += a[i];
//			for(int j = i+1)
//			sum-=a[i];
//		}
//	}
	return 0;
}
