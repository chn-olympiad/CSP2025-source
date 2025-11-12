#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105]={};
	int n,m,cnt;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(&a[1],&a[n*m],cmp);
	for(int i=1;i<=n;i++)    //hang
	{
		for(int j=1;j<=m;j++)    //lie
		{
			if(j%2==1)
			{
				if(cnt==a[n*(j-1)+i])
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
			else
			{
				if(cnt==a[j*n-i+1])
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
