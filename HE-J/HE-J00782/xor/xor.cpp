#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,a;
int main()
{
 	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<int>a(n);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1 && k!=a[0]){
		cout<<0;
		return 0;
	}else if(n==1 && k==a[0]){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k)a++;
	}
	cout<<sum;
return 0;
}
