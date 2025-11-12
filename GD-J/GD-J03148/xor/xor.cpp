#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,a[500005],k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long y=0;
	for(int i=1;i<=n;i++){
		long long x=0;
		for(int j=i;j>y;j--){
			x=x^a[j];
			if(x==k){
				sum++;
				y=i;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
