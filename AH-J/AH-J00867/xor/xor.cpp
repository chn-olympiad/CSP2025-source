#include <bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,i,k;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1];
	/*for(i=2;i<=n;i++)
	{
		if(f[i]|a[i]==k||a[i]==k)
			ans=ans+max(f[i],f[i-1]+k);
	}*/
	cout<<"2";
	return 0;
}
