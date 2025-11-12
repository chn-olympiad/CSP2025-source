#include<bits/stdc++.h>
using namespace std;
int n,m,val;
int a[110];
int col,row;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)val=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==val)
		{
			int cnt=n*m-i+1;
			int piv=cnt%m;
			//cout<<i<<' '<<cnt<<endl;
			if(piv==0)
			{
				//cout<<"fuck ccf\n";
				col=cnt/m;
				if(col%2==0)row=1;
				else row=n;
				break;
			}
			else col=cnt/m+1;
			if(col%2==0)row=n-piv+1;
			else row=piv;
			break;
		}
	}
	cout<<col<<" "<<row;
	return 0;
}
