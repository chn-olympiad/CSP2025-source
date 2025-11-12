#include<iostream>
using namespace std;
int t;
long long n;
int a[3][99999];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int l1=0,l2=0,l3=0,n1=0,n2=0,n3=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[0][j]>>a[1][j]>>a[2][j];
			n1+=a[0][j]>a[1][j]&&a[0][j]>a[2][j];
			l1+=a[0][j]*(a[0][j]>a[1][j]&&a[0][j]>a[2][j]);
			n2+=a[1][j]>a[0][j]&&a[1][j]>a[2][j];
			l2+=a[1][j]*(a[1][j]>a[0][j]&&a[1][j]>a[2][j]);
			n3+=a[2][j]>a[1][j]&&a[2][j]>a[0][j];
			l3+=a[2][j]*(a[2][j]>a[1][j]&&a[2][j]>a[0][j]);
			a[3][j]=1*n1+2*n2+3*n3;
		}
		cout<<l1+l2+l3<<endl;
	}
	return 0;
}
