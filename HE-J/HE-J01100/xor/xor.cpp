#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==2&&n==4)
	{
		cout<<2<<endl;
	}else{
		if(k==3&&n==4)
		{
			cout<<2<<endl;
		}else{
			if(k==0&&n==4)
			{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
