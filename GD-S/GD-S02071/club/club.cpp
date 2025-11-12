#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5];
bool u[100005];
struct sm{
	int w;
	int z;
}b[100005],c[100005],d[100005];
bool cmp(sm f,sm g)
{
    if(f.z<g.z)return 1;
    else return 0;
}
void yx()
{
	bool q=1,z=1;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]); 
		if(a[i][2]!=0||a[i][3]!=0)q=0;
		if(a[i][3]!=0)z=0;
		b[i].z=a[i][1];b[i].w=i;
		c[i].z=a[i][2];c[i].w=i;
		d[i].z=a[i][3];d[i].w=i;
    }
	int num=0;
     if(q==1)
	 {
	 	
       sort(b+1,b+n+1,cmp);
       for(int i=n;i>=n/2+1;i--)
       num+=b[i].z;
       printf("%d\n",num);
       return ;
	} 
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
	sort(d+1,d+n+1,cmp);
	if(z==1)
	{
		for(int i=n,j=n;i>=1,j>=1;i--,j--)
		{
			
		}
	}
	int r1=b[n].z-b[n-1].z;
	int r2=c[n].z-c[n-1].z;
	int r3=d[n].z-d[n-1].z;
	if(b[n].w==c[n].w)
	{
		if(c[n].w==d[n].w)
		{
	        if(r1>r2)num+=b[n].z,u[b[n].w]=1;
	        
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--)
	{
		yx();
	}
	return 0;
} 
