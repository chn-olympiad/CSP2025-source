#include<bits/stdc++.h>
using namespace std;
int n,t,g,h,y,num,w,r,ans;
int a[10001][4];
int f[10001],v;
queue<int> q;
queue<int> q1;
queue<int> q2;
queue<int> q3;
void o(int x)
{
	for(int i=1;i<=x;++i)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]==a[i][2]||a[i][2]==a[i][3]||a[i][1]==a[i][3])
		{
		  q.push(i);
		  num++;	
		} 
		if(a[i][1]>=a[i][2])
		{
			if(a[i][1]>=a[i][3])
			{
				f[i]=a[i][1];
				q1.push(i);
				g++;
			}
			else {f[i]=a[i][3];y++;q3.push(i);}
		}
		else{
			if(a[i][2]>=a[i][3]) {f[i]=a[i][2];h++;q2.push(i);} 
			else {f[i]=a[i][3];y++;q3.push(i);}
		}
	}
	if(g/2>x||h/2>x||y/2>x)
	{
		if(g/2>x)
		{
			
		}
	}
	for(int i=1;i<=x;++i)
		{
			ans=f[i]+ans;
		}
	cout<<ans<<endl;
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		o(n);	
	}
	
	
	return 0;
} 
