#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int n,a[11111],q[11111],ans;
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	q[0]=a[0];
	for(int i=1;i<n;i++)q[i]=q[i-1]+a[i];
	for(int i=0;i<n-2;i++){
		for(int j=i+2;j<n;j++){
			int tp=(q[j]-q[i]);
			if(tp>a[j])ans=(ans+1)%MOD;
		}
	}
	cout<<ans;
	return 0;
} 
