#include<bits/stdc++.h>
using namespace std;
int a[500010],b,n,k;
long long c;
int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
//		cin>>a[i];
		scanf("%d",&a[i]);
//		a[i]^=a[i-1];
//		cout<<a[i]<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		b=0;
		for (int j=i;j<=n;j++)
		{
			b^=a[j];
//			cout<<i<<" "<<j<<" "<<b<<endl;
			if (b==k)
			{
				i=j;
				c++;
				break;
			}
		}
	}
	cout<<c;
//	int f,g;
//	cin>>f>>g;
//	n=f^g;
//	cout<<n;
	return 0;
	fclose(stdin);fclose(stdout);
} 
