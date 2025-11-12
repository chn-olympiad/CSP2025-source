#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],ans;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int pur=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==pur)
		{
			ans=i;
			break; 
		}
	int ans1,ans2;
	ans1=ans/n;
	ans2=ans%n;
	if(ans%n!=0)ans1+=1;
	if(ans2==0)ans2=n;
	if(ans1%2==0)ans2=n-ans2+1;
	cout<<ans1<<' '<<ans2;
	return 0;
}
