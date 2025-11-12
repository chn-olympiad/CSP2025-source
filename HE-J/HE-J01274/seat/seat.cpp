#include<bits/stdc++.h>

using namespace std;
const int MAXN=1000005;
int n,m,a[MAXN];
int c=1,r=1;
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int xp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(c%2!=0)
		{	
			if(a[i]==xp){
				cout<<c<<" "<<r;
				return 0;
			}
			if(r==m) {
				c++;
				continue;	
			}
			r++;
		}else if(c%2==0)
		{
			if(a[i]==xp)
			{
				cout<<c<<" "<<r;
				return 0;
			}
			if(r==1){
				c++;
				continue;	
			}
			r--;
		}
		
	}
	return 0;
}
