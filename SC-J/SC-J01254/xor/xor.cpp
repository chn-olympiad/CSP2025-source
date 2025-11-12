#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
	freopen("xor.in","in","r");
    freopen("xor.ans","out","c");
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==1)
	{
		if(a[1]==0)
		{
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==2)
	{
		if(a[1]==1&&a[2]==1)
		{
			cout<<"1"
		}else{
			cout<<0;
		}
	}
    return 0;
}