#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500005];
long long mmax=0;
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(mmax<a[i])mmax=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i]+a[j]+a[l]>2*mmax)sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}