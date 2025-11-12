#include <bits/stdc++.h>
using namespace std;
int n,m,R;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){  
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int seat[104];
for(int i=1;i<=n*m;i++)
{
	cin>>seat[i];
}
R=seat[1];
sort(seat+1,seat+n*m+1,cmp);
for(int i=1;i<=n*m;i++)
{
	if(R==seat[i])
	{
		if(i%n!=0)//zhongjian lie
		{
			cout<<i/n+1<<" ";
		}
		else
		{
			cout<<i/n<<" ";
		}
		if(i%n!=0)//zhongjian
		{
			if((i/n+1)%2==0)//oushuhang
			{
				cout<<n-(i%n)+1;
			}
			else
			{
				cout<<1;
			}
		}
		else//shouwei
		{
			if((i/n)%2==0)//jishuhang
			{
				cout<<i%n;
			}
			else
			{
				cout<<n;
			}
		}
	}
}
fclose(stdin);
fclose(stdout);
return 0;
}
