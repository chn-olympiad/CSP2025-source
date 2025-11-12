#include<bits/stdc++.h>
using namespace std;
int ans,i,a[500001],j,m,n,k,aa0,aa1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] == 0)
		{
			aa0++;
		}if(a[i] == 1)
		{
			aa1++;
		}
	}
	if(k == 0)
	{
		cout<<aa0 + aa1 / 2<<endl;
	 } 
	 if(k == 1)
	 {
	 	cout<<aa1<<endl;
	 }
	
}
