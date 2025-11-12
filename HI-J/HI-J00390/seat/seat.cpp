#include<bits/stdc++.h>
using namespace std;
int a[10009],b[100][100],c[10000];
int cmp(int x,int y)
{
	if(x!=y)
		return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt=0;
	for(int i=0;i<n*m;i++)
	{
		cin >> a[i];
		cnt=a[0];
	}
	sort(a,a+n*m,cmp);
	int sum=0;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==cnt)
			sum=i+1;
	}
	if(sum%n==0)
		cout << sum/n<<" ";
	else if(sum%n==1)
		cout << sum/n+1<<" ";
	if(sum%m==1||sum%m==0)
		cout << sum/m+1;		
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


