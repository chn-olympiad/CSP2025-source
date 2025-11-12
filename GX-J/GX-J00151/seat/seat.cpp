#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
int n,m,flag,cnt;
int a[110];
bool cmp(int x,int y)
{
		return x>y;
}

int main()
{
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
		flag=a[1];
		sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=m*n;i++)
		{
				int ans;
				if(i%n!=0)	ans=i/n+1;
				else ans=i/n;	
		//		cout<<ans;
				if(flag==a[i])
				{
					if(ans%2==1)
					{
						if(i%m!=0)
							cout<< ans<<' '<<i%m;
						else
							cout<< ans<<' '<<m;
					}
					//-------------------------------
						if(ans%2==0)
					{
						if(i%m!=0)
							cout<< ans<<' '<<(m+1)-i%m;
					}
				}
		}
		return 0;
}
