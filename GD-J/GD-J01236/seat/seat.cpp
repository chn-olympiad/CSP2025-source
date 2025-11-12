#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			int s=0,t=0;
			if(i%n==0) 
			{
				t=i/n;
				if(t%2==0) s=1;
				else s=n;
			}
			else 
			{
				t=i/n+1;
				if(t%2==0) s=n-i%n+1;
				else s=i%n;	
			} 
			printf("%d %d",t,s);
			return 0;
		}
	}
	return 0;
}
