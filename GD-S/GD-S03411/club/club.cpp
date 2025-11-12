#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005],b,c,s,t1,t2;
bool pA,pB;
struct node 
{
	int x,y;
}t[100005];
bool cmp(node a,node b)
{
	return max(a.x,a.y)>max(b.x,b.y);
}
bool cmp1(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		pA=1,pB=1,s=0,t1=0,t2=0;;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b>>c;
			if(b!=0 || c!=0) pA=0;
			if(c!=0) pB=0;
			s+=a[i];
			t[i].x=b-a[i],t[i].y=c-a[i];
		}
		if(pA==1)
		{
			sort(a+1,a+1+n);
			s=0;
			for(int i=n;i>n/2;i--)
			{
				s+=a[i];
			}
			cout<<s<<endl;
			continue;
		}
		if(pB==1)
		{
			sort(t+1,t+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				s+=t[i].x;
			}
			cout<<s<<endl;
			continue;
		}
		sort(t+1,t+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(t[i].x<0 && t[i].y<0 && i>n/2) break;
			if(t1<n/2 && t2<n/2)
			{
				s+=max(t[i].x,t[i].y);
				if(t[i].x>t[i].y) t1++;
				else t2++;
			}
			else if(t1==n/2 && t2<n/2 && t[i].y>=0) s+=t[i].y,t2++;
			else if(t2==n/2 && t1<n/2 && t[i].x>=0) s+=t[i].x,t1++;
			//cout<<s<<" "<<t1<<" "<<t2<<endl;
		}
		cout<<s<<endl;
	}
	return 0;
}

