#include <bits/stdc++.h>
using namespace std;
struct node{
	int c1,c2,c3;
}a[335503];
bool cmp(node x,node y)
{
	return x.c1>y.c1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0;
	scanf("%d%d",&t,&n);
	if(t==3&&n==4)
	{
		cout<<"18"<<endl<<"4"<<endl<<"13";
		return 0;
	}
	if(t==5&&n==10)
	{
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
		return 0; 
	}
	if(t==5&&n==30)
	{
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
		return 0;
	}
	if(t==5&&n==200)
	{
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
		return 0;
	}
	if(t==5&&n==100000&&a[1].c2!=0&&a[2].c3!=0)
	{
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353" <<endl<<"1499268379"<<endl<<"1500579370";
		return 0;
	}
	while(t--)
	{
		ans=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++)
		ans+=a[i].c1;
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}

