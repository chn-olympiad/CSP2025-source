#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct poi{
	int x,y;
};
poi q[100005],w[100005],e[100005];
int f[100005][3],n,t,i,j,k ,x[3][3],y[3][3],p1,p2,p3;
bool c[10005][3];
bool cmp(poi z1,poi x1){return z1.x>x1.x;}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0; i<3; i++)
			for(j=0; j<3; j++)
				x[i][j]=y[i][j]=0;
		x[0][0]=x[1][1]=x[2][2]=1;
		for(i=0; i<n; i++)
			cin>>q[i].x>>w[i].x>>e[i].x,
			q[i].y=w[i].y=e[i].y=i,c[i][0]=c[i][1]=c[i][2]=1;
		sort(q,q+n,cmp),sort(w,w+n,cmp),sort(e,e+n,cmp);
		
		f[0][0]=q[0].x,f[0][1]=w[0].x,f[0][2]=e[0].x;
		
		for(i=1; i<n; i++)
			for(j=0; j<3; j++){
				p1=x[0][j],p2=x[1][j],p3=x[2][j];
				while(c[p1][j]==0&&y[0][j]<n/2&&p1<n&&p1==x[0][j])p1++;
				while(c[p2][j]==0&&y[1][j]<n/2&&p2<n&&p2==x[1][j])p2++;
				while(c[p3][j]==0&&y[2][j]<n/2&&p3<n&&p3==x[2][j])p3++;
				
				if(q[p1].x>=w[p2].x&&q[p1].x>=e[p3].x)
				
					x[0][j]=p1,y[0][j]++,c[p1][j]=0,
					f[i][j]=f[i-1][j]+q[p1].x;
				
				else if(w[p1].x>=q[p2].x&&w[p2].x>=e[p3].x)
				
					x[1][j]=p2,y[1][j]++,c[p2][j]=0,
					f[i][j]=f[i-1][j]+w[p2].x;
					
				else
					x[2][j]=p3,y[2][j]++,c[p3][j]=0,
					f[i][j]=f[i-1][j]+e[p3].x;
			}
		cout<<max(f[n-1][0],max(f[n-1][1],f[n-1][2]))<<'\n';
	}
	return 0;
}
