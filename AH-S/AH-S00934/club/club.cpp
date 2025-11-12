#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int t,n,mx;
bool cmp(node n,node m){
	return n.x>m.x;
}
void dfs1(int cnt,int s,int s1,int s2,int s3){
	if(cnt==n+1)
	{
		mx=max(mx,s);
		return;
	}
	if(s1<n/2)
		dfs1(cnt+1,s+a[cnt].x,s1+1,s2,s3);
	if(s2<n/2)
		dfs1(cnt+1,s+a[cnt].y,s1,s2+1,s3);
}
void dfs(int cnt,int s,int s1,int s2,int s3){
	if(cnt==n+1)
	{
		mx=max(mx,s);
		return;
	}
	if(s1<n/2)
		dfs(cnt+1,s+a[cnt].x,s1+1,s2,s3);
	if(s2<n/2)
		dfs(cnt+1,s+a[cnt].y,s1,s2+1,s3);
	if(s3<n/2)
		dfs(cnt+1,s+a[cnt].z,s1,s2,s3+1);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
		mx=0;
		int ok1=1,ok2=1;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) ok1=0;
			if(a[i].z!=0) ok2=0;
		}
		if(ok1==ok2 && ok2==1)
		{
			sort(a+1,a+n+1,cmp);
			int s=0;
			for(int i=1; i<=n/2; i++)
				s+=a[i].x;
			cout<<s<<"\n";
			continue;
		}
		if(ok2)
		{
			dfs1(1,0,0,0,0);
			cout<<mx<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<mx<<"\n";
	}
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
