#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],b[105][105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	//小R为什么不看准考证 
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	b[1][1]=a[1];
	b[2][1]=a[2*n];
	int o=0; 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i%2==1)
			{
				b[j][i]=a[o*n+j];
			}
			else
			{
				b[j][i]=a[o*n+n-j+1];
			}
		}
		//只要你数学够好就不用管那么多直接列公式    
		o++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]==p)
				cout<<i<<" "<<j; 
		}
	}
	//我突然想明白了我看了准考证一开始也不知道坐哪，这个程序太有用了 
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
