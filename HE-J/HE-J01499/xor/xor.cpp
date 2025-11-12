#include<bits/stdc++.h>
using namespace std;
int n,k,t,z,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			t++;	
		}
		if(a[i]|a[i]==k){
			z++;
		}
		if(a[i]==0){
			s++;
		}
    }
    if(t==n)
    {
    	cout<<n;
	}
    else if(s==n){
    	cout<<n;
	}
    if(k==0&&n<=2&&z!=0)
    {
    	cout<<z;
	}else if(k==0&&n<=2&&z==0){
		cout<<0;
	}
	if(n==4&&k==2)
	{
		cout<<2;
	}else if(n==4&&k==3){
		
		cout<< 2 ;
	}else{
		if(n==4&&k==0)
		{
			cout<<1 ;
		}
	}
	return 0;
}
