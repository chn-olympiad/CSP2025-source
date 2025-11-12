#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cj[1000];
	for(int i=1;i<=n*m;i++)
	{
		cin>>cj[i];
	}
	int u=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(u==cj[i])
		{
			int ans1=ceil(i*1.0/n);
			int ans2=i%n;
			if(ans2==0) ans2=n;
			if(ans1%2==1)
			{
				cout<<ans1<<' '<<ans2;
				return 0;
			}
			else 
			{
				ans2=n-ans2+1;
				cout<<ans1<<' '<<ans2;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

