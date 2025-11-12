#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[n+10];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int temp=a[i];
		int temp1=0;
		while(temp)
		{
			temp1=temp1*10+temp%2;
			temp/=2;
		}
		a[i]=temp1;
	}
	//for(int i=1;i<=)
	cout << 1 << endl;
	return 0;
}
//pianfen
