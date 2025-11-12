#include<bits/stdc++.h>
using namespace std;
struct jcc{
	int x,y,z,d;
}a[100005];
int bm=0;
int n;
void sx(int x,int y,int z,int sl,int wz)
{
	if(wz==n+1) 
	{
		bm=max(bm,sl);
	}
	else if(x<n/2) sx(x+1,y,z,sl+=a[wz].x,wz+1);
	else if(y<n/2) sx(x,y+1,z,sl+=a[wz].y,wz+1);
	else if(z<n/2) sx(x,y,z+1,sl+=a[wz].z,wz+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		bm=0;
		sx(0,0,0,0,1);
		cout<<bm<<endl;
	}
	return 0;
}
