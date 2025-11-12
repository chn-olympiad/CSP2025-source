#include<bits/stdc++.h> 
using namespace std;
struct A{
	int e1,e2,e3,i,maxi;
};
bool cmp(A x,A y)
{
	return x.i>y.i;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,s=0;
		A a[100005];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].e1>>a[i].e2>>a[i].e3;
			a[i].i=max(max(a[i].e1,a[i].e2),a[i].e3)*2+min(min(a[i].e1,a[i].e2),a[i].e3)-a[i].e1-a[i].e2-a[i].e3;
			if(a[i].e1==max(max(a[i].e1,a[i].e2),a[i].e3))
				{
					a[i].maxi=0;
				}
			if(a[i].e2==max(max(a[i].e1,a[i].e2),a[i].e3))
				{
					a[i].maxi=1;
				}
				if(a[i].e3==max(max(a[i].e1,a[i].e2),a[i].e3))
				{
					a[i].maxi=2;
				}
			s+=max(max(a[i].e1,a[i].e2),a[i].e3);
		}
		sort(a+1,a+n+1,cmp);
		int k[3]={0,0,0};
		for(int i=1;i<=n;i++)
		{
			k[a[i].maxi]++;
			if(k[a[i].maxi]>n/2)
			{
				s-=a[i].i;
			}
		}
		cout<<s<<endl;
	}
}
