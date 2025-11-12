#include<bits/stdc++.h>
using namespace std;
long long a[5009],n,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3&&a[1]+a[2]>a[3]){cout<<"1";return 0;}
}
