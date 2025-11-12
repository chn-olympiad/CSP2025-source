#include<bits/stdc++.h> 
using namespace std;
int main(){
//	freopen("polygon1.in","r",stdin);
//	freopen("polygon1.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[10];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				int d=a[i];
				a[i]=a[j];
				a[j]=d;
			}
		}
	}
	if(a[1]+a[2]+a[3]>a[1]*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
