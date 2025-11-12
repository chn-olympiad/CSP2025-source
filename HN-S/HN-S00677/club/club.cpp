#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int a[n][3],b;
		for(int i2=0;i2<n;i2++)
		{
			for(int i3=0;i3<3;i3++)
			{
				cin>>a[i2][i3];
			}
		}
		for(int i2=0;i2<n;i2++)
		{
			for(int i3=0;i3<3;i3++)
			{
				for(int i4=i3;i4<3;i4++)
				{
					if(a[i2][i3]<a[i2][i4])
					{
						b=a[i2][i3];
						a[i2][i3]=a[i2][i4];
						a[i2][i4]=b;
					}
				}
			}
		}
		b=0;
		for(int i2=0;i2<n;i2++)
		{
			b=b+a[i2][0];
		}
		cout<<b;
	}
	return 0;
} 
