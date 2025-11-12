#include<bits/stdc++.h>
using namespace std;
int a[1000006];
long long qwe,n,m,sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n<=4)
	{
		for(int i=3;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
				qwe=0;
				m=0;
				for(int k=j;k<j+i;k++)
					{
						if(a[k]>qwe) qwe=a[k];
						m+=a[k];
					}
				if(2*qwe<m) sum++;
			}
		cout<<sum;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
