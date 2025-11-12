#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int chengji=a[1];
	sort(a+1,a+n*m+1);
	int num=lower_bound(a+1,a+n*m+1,chengji)-a;
	num=n*m-num+1;
	int lie=num/n+bool(num%n);
	cout<<lie<<' ';
	if(lie%2)//前->后 
	{
		if(num%n==0)
			cout<<n;
		else
			cout<<num%n<<endl;
	}
	else//后->前 
	{
		if(num%n==0)
			cout<<1<<endl;
		else
			cout<<n-(num%n)+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
