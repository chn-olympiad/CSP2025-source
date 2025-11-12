#include<bits/stdc++.h>
using namespace std;
int const N=10005;
int a[N];
int n,m,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	int r=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>r) num++;
	}
	//cout<<num<<endl;
	int x=int(num/n)+1,y=num%n+1;
	if(x%2==0)
		cout<<x<<" "<<m-y+1<<endl;
	 else
		cout<<x<<" "<<y<<endl;
	return 0;
}
