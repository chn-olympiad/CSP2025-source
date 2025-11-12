#include<bits/stdc++.h>
using namespace std;
struct stu{
	int id;
	int mn;
};
int n,m;
stu a[105];
bool cmp(stu a,stu b)
{
	return a.mn>b.mn;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].mn;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			cnt=i;
			break;
		}
	}
	int c,r;
	if(cnt%n==0)
	{
		c=cnt/n;
		if((cnt/n)%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		c=cnt/n+1;
		if((cnt/n+1)%2==0)
		{
			r=n-(cnt%n)+1;
		}
		else
		{
			r=cnt%n;
		}
	}
	cout<<c<<' '<<r;
	//CCF are sb!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//fuck ccf's mother£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	//ccf don't have 78 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
