#include<iostream>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int a[1001][1001];
	int t,n,j,s;
	cin>>t;
	for(int x=1;x<=t;++x)
	{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=3;++j)
		{
			cin>>a[i][j];
		}
	}
    }
    for(int x=1;x<=t;++x)
	{
	 for(int i=n;i>=1;--i)
	 {
		for(j=1;j<=3;++j)
		{
			if(a[i][j]>a[i][j+1])
			  swap(a[i][j],a[i][j+1]);
			
		}
		s=s+a[i][j];
	 }
	 cout<<s<<endl;
    }
	return 0;
    fclose(stdin);
    fclose(stdout);
}
