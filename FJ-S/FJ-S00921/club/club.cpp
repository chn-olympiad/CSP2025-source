#include<bits/stdc++.h>
using namespace std;
struct i
{
	int x,y,z;
}xx[100101],yy[100101],zz[100101];
bool cmp(i a,i b)
{
	if(a.x==0) return min(a.y,a.z)<min(b.y,b.z);
	if(a.y==0) return min(a.x,a.z)<min(b.x,b.z);
	return min(a.x,a.y)<min(b.x,b.y); 
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int t,n,lx,ly,lz,xt,yt,zt,e;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		xt=0,yt=0,zt=0,e=0;
		cin>>n;
		for(int c=1;c<=n;c++)
		{
			cin>>lx>>ly>>lz;
			if(lx>=ly&&lx>=lz) xx[++xt].x=0,xx[xt].y=ly-lx,xx[xt].z=lz-lx,e+=lx;
			else if(ly>=lx&&ly>=lz) yy[++yt].x=lx-ly,yy[yt].y=0,yy[yt].z=lz-ly,e+=ly;
			else zz[++zt].x=lx-lz,zz[zt].y=ly-lz,zz[zt].z=0,e+=lz;
		}
		if(xt>n/2)
		{
			sort(xx+1,xx+xt+1,cmp);
			for(int c=1;c<=xt-n/2;c++)
			{
				if(xx[c].y==xx[c].z)
			}
		}
	}
	return 0;
}
