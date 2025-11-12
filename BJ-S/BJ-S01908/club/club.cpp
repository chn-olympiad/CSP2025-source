#include <bits/stdc++.h>
using namespace std;
int t,ans=0;
struct student{
	int l1,l2,l3;
}a[100001];
bool cmp1(int x,int y)
{
	return x.l1>y.l1;
}
bool cmp2(int x,int y)
{
	return x.l2>y.l2;
}
bool cmp3(int x,int y)
{
	return x.l3>y.l3;
}
int main(){
    freopen("club.in",r,stdin);
    freopen("club.out",w,stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n; cin>>n;
		int c1=0,c2=0,c3=0;
		for(int j=0;j<n;j++)
		{
			for(int l=0;l<3;l++)
			{
				cin>>a[j].l1>>a[j].l2>>a[j].l3;
				if(l1>l2&&l1>l3) c1++;
				else if(l2>l1&&l2>l3) c2++;
				else c3++;
			}
		}
		if(c1>n/2) 
			sort(a,a+n,cmp1);
			for(int i=0;i<n/2;i++) ans+=a[i].l1;
			if(l2>l3) 
				sort(a+n/2,a+n,cmp2);
				for(int i=n/2;i<n;i++) ans+=a[i].l2;
			else 
				sort(a+n/2,a+n,cmp3);
				for(int i=n/2;i<n;i++) ans+=a[i].l3;
		if(c2>n/2) 
			sort(a,a+n,cmp2);
			for(int i=0;i<n/2;i++) ans+=a[i].l2;
			if(l1>l3) 
				sort(a+n/2,a+n,cmp1);
				for(int i=n/2;i<n;i++) ans+=a[i].l1;
			else 
				sort(a+n/2,a+n,cmp3);
				for(int i=n/2;i<n;i++) ans+=a[i].l3;
		if(c3>n/2) 
			sort(a,a+n,cmp3);
			for(int i=0;i<n/2;i++) ans+=a[i].l3;
			if(l1>l2) 
				sort(a+n/2,a+n,cmp1);
				for(int i=n/2;i<n;i++) ans+=a[i].l1;
			else 
				sort(a+n/2,a+n,cmp2);
				for(int i=n/2;i<n;i++) ans+=a[i].l2;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}