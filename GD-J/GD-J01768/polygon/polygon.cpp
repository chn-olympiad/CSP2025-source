#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],s[10005],sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(sum>2*a[n]) cout<<1;
	else cout<<0;
	return 0;
}
