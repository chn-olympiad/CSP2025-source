#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum1=0,sum2=0;
int a[100001];
int b[100001];
signed main(){
	freopen("polygon.in","l",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]-b[i-1])>2*a[j]){
				sum1++;
				for(int k=i+1;k<=j;k++){
					if(b[j]-a[k]-b[i-1]>2*a[j]) sum1++;
					else break;
				}
			}
		}
	}
	cout<<sum1%998244353;
	return 0;
}