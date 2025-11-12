#include <bits/stdc++.h>//判断函数已完成，惜败 
using namespace std;	
int h=0;
void q(int w){
		for (int j=w;j>=1;j--)
		{
			for(int l=j;l>=1;l--)
			{
				h+=l;
			}
		}
}
int a[5100];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(int i=3;i<=n;i++)
	{
		int w=n-i+1;
		q(w);
	}
	cout<<h;
	return 0;
}

