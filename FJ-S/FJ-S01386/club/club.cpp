#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}f[100005];
int t,n,p[100005],a[100005],b[100005],c[100005],la=0,lb=0,lc=0,s;
int cmp(int g,int h)
{
	return f[g].x>f[h].x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		la=lb=lc=s=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&f[j].x,&f[j].y,&f[j].z);
			if(f[j].x>=f[j].y&&f[j].x>=f[j].z)
			{
				s+=f[j].x;
				a[++la]=j;
			}
			else if(f[j].y>=f[j].x&&f[j].y>=f[j].z)
			{
				s+=f[j].y;
				b[++lb]=j;
			}
			else
			{
				s+=f[j].z;
				c[++lc]=j;
			}
		}
		n/=2;
		if(n>=la&&n>=lb&&n>=lc) cout<<s<<endl;
		else
		{
			sort(a+1,a+la+1,cmp);
			sort(b+1,b+lb+1,cmp);
			sort(c+1,c+lc+1,cmp);
			if(la>n)
			{
				while(la>n)
				{
					if(f[a[la]].y>=f[a[la]].z)
					{
						b[++lb]=a[la];
						s+=f[a[la]].y-f[a[la]].x;
					}
					else
					{
						c[++lc]=a[la];
						s+=f[a[la]].z-f[a[la]].x;
					}
					la--;
				}
			}
			else if(lb>n)
			{
				while(lb>n)
				{
					if(f[b[lb]].x>=f[b[lb]].z)
					{
						a[++la]=b[lb];
						s+=f[b[lb]].x-f[b[lb]].y;
					}
					else
					{
						c[++lc]=b[lb];
						s+=f[b[lb]].z-f[b[lb]].y;
					}
					lb--;
				}
			}
			else if(lc>n)
			{
				while(lc>n)
				{
					if(f[c[lc]].x>=f[c[lc]].y)
					{
						a[++la]=c[lc];
						s+=f[c[lc]].x-f[c[lc]].z;
					}
					else
					{
						b[++lb]=c[lc];
						s+=f[c[lc]].y-f[c[lc]].z;
					}
					lc--;
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
