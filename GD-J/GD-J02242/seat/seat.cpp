#include<bits/stdc++.h>
using namespace std;
int n,m,nowx=1,nowy=1,a[103],ans;
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
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
//		cout<<"ans:"<<a[i]<<" "<<nowx<<":"<<nowy<<endl;
		if(a[i]==ans)
		{
			cout<<nowx<<" "<<nowy;
			return 0;
		}
		if((nowy==n&&nowx%2==1)||(nowy==1&&nowx%2==0))nowx++;
		else if(nowx%2==0)nowy--;
		else if(nowx%2==1)nowy++;
	}
} 
