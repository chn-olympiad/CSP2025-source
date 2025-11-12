#include<bits/stdc++.h>
using namespace std;
int a[1002];//ying1 gai1 gou4 le4 ba0
int m,n;
int alen;
int wz,cj;
int c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	alen=n*m;
	for(int i=1;i<=alen;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
//	cout<<"cj=="<<cj<<"alen=="<<alen<<endl;//debug
	sort(a+1,a+alen,cmp);
//	wz=upper_bound(a+1,a+alen,cj);
//	for(int i=1;i<=alen;i++)
//	{
//		cout<<a[i];
//	}
//	for(int i=1;i<=m;i++)//mo ni 1*2==2*1
//	{
////		cout<<"i="<<i;
//		if(i%2==1)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(a[(i-1)*j+j]==cj)
//				{
//					cout<<i<<" "<<j;
////					cout<<"i%2==1--------------------";
//					return 0;
//				}
////				cout<<a[i*j]<<" ";
////				cout<<"j="<<j;
//			}
//		}
//		else
//		{
//			for(int j=n;j>=1;j--)
//			{
//				if(a[(i-1)*j+j]==cj)
//				{
//					cout<<i<<" "<<j;
////					cout<<"i%2==0--------------------";
//					return 0;
//				}
////				cout<<a[i*j]<<" ";
////				cout<<"j="<<j;
//			}
//		}
////		cout<<endl;
//	}
//--------------------------------------------------------
	for(int i=1;i<=alen;i++)//shu xue
	{
		if(a[i]==cj)
		{
			wz=i;
		}
	}
	c=wz/n;
	if(wz%n!=0)
	{
		c++;
	}
	if(c%2==1)
	{
		if(wz%n==0)
		{
			r=n;
		}
		else
		r=wz%n;
	}
	else
	{
		if(wz%n==0)
		{
			r=1;
		}
		else
		r=n-(wz%n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
