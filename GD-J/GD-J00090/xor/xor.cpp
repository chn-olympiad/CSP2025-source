#include <iostream>
#include <cmath>
using namespace std;
long long n;
int a[int(5e5)]={};
long long k;
long long sum;
long long b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1,r=1;l<=n;l++){
		r=l,b=a[l];
		while(b!=k&&r<n)b^=a[++r];
		if(b==k)sum++,l=r;
		else break;
	}
	cout<<sum;
	return 0;
}
