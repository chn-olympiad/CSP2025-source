#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int add;
int ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int total=n*m;
	for(int i=1;i<=total;i++)
		{
			cin>>a[i];
		}
	int goal=a[1];
	sort(a,a+total+1);
	for(int i=1;i<=total;i++)
	{
		if(a[i]==goal)
		{
			//cout<<endl;
			//cout<<goal<<" "<<i;
			add=total-i+1;
			break;
		}
	}
	//cout<<endl<<add<<endl;
	ansm=add/n;
	if(add%n!=0)
	{
		ansm++;
	}
	ansn=(add%n);
	if(ansn==0)
	{
		ansn=n;
	}
	if(ansm%2==0)
	{
		ansn=n-ansn+1;
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}
