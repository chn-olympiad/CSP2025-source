#include<bits/stdc++.h>
using namespace std;
int T,ans;
const int N=1e5+10;
struct Node{
	int x,y,z,ans1;
}a[N];
bool cmp1(Node a,Node b)
{
	return a.ans1>b.ans1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		int n,x1=0,y91=0,z1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].ans1=a[i].x+a[i].y+a[i].z;
		}
		int k=n/2;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&x1<k)
				ans+=a[i].x,x1++;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&y91<k)
				ans+=a[i].y,y91++;
			else if(z1<k)
				ans+=a[i].z,z1++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}//90zzc
//BLCQJ,DBCSY,SNOIYCK,BK long long JZZ,SSNOI,SSNCSP,MQSNMJQ!
//13131313131313131313131313*7=?
