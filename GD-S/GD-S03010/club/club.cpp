#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
int T,n;
struct X{
	int x,y,z,zd,cd;
}a[N];
bool cmpx(X a,X b){
	if(a.zd==1&&b.zd==1)
	{
		if(a.cd==2&&b.cd==2)return a.x-a.y<b.x-b.y;
		if(a.cd==3&&b.cd==3)return a.x-a.z<b.x-b.z;
		if(a.cd==3&&b.cd==2)return a.x-a.z<b.x-b.y;
		if(a.cd==2&&b.cd==3)return a.x-a.y<b.x-b.z;
	}
	return a.zd==1;
}
bool cmpy(X a,X b){
	if(a.zd==2&&b.zd==2)
	{
		if(a.cd==1&&b.cd==1)return a.y-a.x<b.y-b.x;
		if(a.cd==3&&b.cd==3)return a.y-a.z<b.y-b.z;
		if(a.cd==1&&b.cd==3)return a.y-a.x<b.y-b.z;
		if(a.cd==3&&b.cd==1)return a.y-a.z<b.y-b.x;
	}
	return a.zd==2;
}
bool cmpz(X a,X b){
	if(a.zd==3&&b.zd==3)
	{
		if(a.cd==1&&b.cd==1)return a.z-a.x<b.z-b.x;
		if(a.cd==2&&b.cd==2)return a.z-a.y<b.z-b.y;
		if(a.cd==1&&b.cd==2)return a.z-a.x<b.z-b.y;
		if(a.cd==2&&b.cd==1)return a.z-a.y<b.z-b.x;
	}
	return a.zd==3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ret=0,sx=0,sy=0,sz=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				sx++,a[i].zd=1,ret+=a[i].x;
				if(a[i].y>=a[i].z)a[i].cd=2;
				else a[i].cd=3;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				sy++,a[i].zd=2,ret+=a[i].y;
				if(a[i].x>=a[i].z)a[i].cd=1;
				else a[i].cd=3;
			}
			else
			{
				sz++,a[i].zd=3,ret+=a[i].z;
				if(a[i].x>=a[i].y)a[i].cd=1;
				else a[i].cd=2;
			}
		}
		if(sx>n/2)
		{
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n;i++)
			{
				if(a[i].zd!=1||sx<=n/2)break;
				sx--;
				if(a[i].cd==2)sy++,ret=ret-a[i].x+a[i].y;
				else sz++,ret=ret-a[i].x+a[i].z;				
			}
		}
		if(sy>n/2)
		{
			sort(a+1,a+n+1,cmpy);
			for(int i=1;i<=n;i++)
			{
				if(a[i].zd!=2||sy<=n/2)break;
				sy--;
				if(a[i].cd==1)sx++,ret=ret-a[i].y+a[i].x;
				else sz++,ret=ret-a[i].y+a[i].z;				
			}
		}
		if(sz>n/2)
		{
			sort(a+1,a+n+1,cmpz);
			for(int i=1;i<=n;i++)
			{
				if(a[i].zd!=3||sz<=n/2)break;
				sz--;
				if(a[i].cd==2)sy++,ret=ret-a[i].z+a[i].y;
				else sx++,ret=ret-a[i].z+a[i].x;				
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}

