#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sore[n*m+1];
	cin>>sore[1];
	int rs=sore[1];
	for (int i=2;i<=n*m;i++)
	{
		cin>>sore[i];
	}
	sort(sore+1,sore+n*m+1);
	for (int i=1;i<=n*m/2;i++)
	{
		int mid=sore[i];
		sore[i]=sore[n*m-i+1];
		sore[n*m-i+1]=mid;
	}
	
	int row[n*m+1],line[n*m+1];
	int group=1;
	for (int i=1;i<=n*m;i+=n)
	{
		for (int j=i;j<=i+m-1;j++)
		{
			row[j]=group;
			if(group%2==1)
			{
				line[j]=j-(group-1)*n;
			}
			else
			{
				line[j]=i+n-j;
			}
		}
		
		group++;
	}
	for (int i=1;i<=n*m;i++)
	{
		if(sore[i]==rs)
		{
			cout<<row[i]<<' '<<line[i];
		}
	}
	return 0;
}
