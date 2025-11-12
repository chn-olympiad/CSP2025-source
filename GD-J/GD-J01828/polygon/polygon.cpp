#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e3+10;
long long n,a[maxn],b[maxn],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)    cin>>b[i];
	sort(b+1,b+1+n);
	for(long long i=1;i<=n;i++)    a[i]=a[i-1]+b[i];
	for(long long i=3;i<n;i++){
		if(b[i]>=a[i-1])    continue;
		for(long long j=1;j<i;j++){
			for(long long k=j;k<=i;k++){
				if(a[i]-a[k]+a[k-j+1]>=b[i])    sum++;
			}
		}
	}
	if(a[n-1]>b[n])    sum++;
	cout<<sum%998224353;
	return 0;
}
