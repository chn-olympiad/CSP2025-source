#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int a,int b)
{
	if(a>b) return true;
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int xr=a[1];//xiao r's grades
	sort(a,a+sizeof(a)+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				k++;
				if(a[k]==xr)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				k++;
				if(a[k]==xr)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
}
