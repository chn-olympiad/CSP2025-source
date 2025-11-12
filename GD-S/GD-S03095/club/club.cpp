#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e5+42,INF=0x3f3f3f3f;
struct s
{
	int a,b,c,maxx;
	void in()
	{
		cin>>a>>b>>c;
		maxx=max(a,max(b,c));
	}
}arr[N];
bool cmp(s &a,s &b)
{
	return a.a<b.a;
}
bool cmq(s &a,s &b)
{
	return a.b<b.b;
}
bool cmb(s &a,s &b)
{
	return a.c<b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			arr[i].in();
		}
		sort(arr+1,arr+n+1,cmp);
		int cnt=0;
		for(int i=n;i>0;i--)
		{
			if(cnt==n/2)break;
			if(arr[i].a==arr[i].maxx)
			{
				cnt++;
				sum+=arr[i].a;
				arr[i].b=arr[i].c=0; 
			}
		}
		sort(arr+1,arr+n+1,cmq);
		cnt=0;
		for(int i=n;i>0;i--)
		{
			if(cnt==n/2)break;
			if(arr[i].b>arr[i].c)
			{
				cnt++;
				sum+=arr[i].b;
				arr[i].c=0; 
			}
		}
		sort(arr+1,arr+n+1,cmb);
		cnt=0;
		for(int i=n;i>0;i--)
		{
			if(cnt==n/2)break;
			sum+=arr[i].c;
			cnt++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
