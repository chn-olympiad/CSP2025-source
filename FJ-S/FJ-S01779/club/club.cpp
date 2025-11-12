#include<bits/stdc++.h>
using namespace std;
int m[100005][4],maxn[100005],maxi[100005],r[4]={0,0,0,0};
		struct str
		{
			int z,i;
		}xa[100005],xb[100005],xc[100005];
bool cmpa(str x,str y)
{
	int mmx,mmy;
	if(m[x.i][2]>m[x.i][3])
	{
		mmx=m[x.i][2];	
	}
	else 
	{
		mmx=m[x.i][3];
	}
	if(m[y.i][2]>m[y.i][3])
	{
		mmy=m[y.i][2];	
	}
	else 
	{
		mmy=m[y.i][3];
	}
	return x.z-mmx>y.z-mmy;
}
bool cmpb(str x,str y)
{
	int mmx,mmy;
	if(m[x.i][1]>m[x.i][3])
	{
		mmx=m[x.i][1];	
	}
	else 
	{
		mmx=m[x.i][3];
	}
	if(m[y.i][1]>m[y.i][3])
	{
		mmy=m[y.i][1];	
	}
	else 
	{
		mmy=m[y.i][3];
	}
	return x.z-mmx>y.z-mmy;
}
bool cmpc(str x,str y)
{
	int mmx,mmy;
	if(m[x.i][2]>m[x.i][1])
	{
		mmx=m[x.i][2];	
	}
	else 
	{
		mmx=m[x.i][1];
	}
	if(m[y.i][2]>m[y.i][1])
	{
		mmy=m[y.i][2];	
	}
	else 
	{
		mmy=m[y.i][1];
	}
	return x.z-mmx>y.z-mmy;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		r[1]=0;
		r[2]=0;
		r[3]=0;
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxi[i]=0;
			maxn[i]=0;
			for(int j=1;j<=3;j++)	
			{
				cin>>m[i][j];
				if(m[i][j]>maxn[i])
				{
					maxi[i]=j;
					maxn[i]=m[i][j];
				}
			}
			r[maxi[i]]++;
			if(maxi[i]==1)	{
				xa[r[maxi[i]]].z=maxn[i];
				xa[r[maxi[i]]].i=i;
			}
			if(maxi[i]==2)	{
				xb[r[maxi[i]]].z=maxn[i];
				xb[r[maxi[i]]].i=i;
			}
			if(maxi[i]==3)	{
				xc[r[maxi[i]]].z=maxn[i];
				xc[r[maxi[i]]].i=i;
			}
		}
		while(r[1]>n/2||r[2]>n/2||r[3]>n/2)
		{
			if(r[1]>n/2)
			{
				sort(xa+1,xa+r[1]+1,cmpa);
				int mm=0;
				if(m[xa[r[1]].i][2]>m[xa[r[1]].i][3])
				{
					mm=m[xa[r[1]].i][2];
					r[2]++;
					xb[r[2]].z=mm;
					xb[r[2]].i=xa[r[1]].i;
				}
				else {
					mm=m[xa[r[1]].i][3];
					r[3]++;
					xc[r[3]].i=xa[r[1]].i;
				}
				r[1]--;
			}
			if(r[2]>n/2)
			{
				sort(xb+1,xb+r[2]+1,cmpb);
				int mm=0;
				if(m[xb[r[2]].i][1]>m[xb[r[2]].i][3])
				{
					mm=m[xb[r[2]].i][1];
					r[1]++;
					xa[r[1]].z=mm;
					xa[r[1]].i=xb[r[2]].i;
				}
				else {
					mm=m[xb[r[2]].i][3];
					r[3]++;
					xc[r[3]].i=xb[r[2]].i;
				}
				r[2]--;
			}
			if(r[3]>n/2)
			{
				sort(xc+1,xc+r[1]+1,cmpc);
				int mm;
				if(m[xc[r[3]].i][1]>m[xc[r[3]].i][2])
				{
					mm=m[xc[r[3]].i][1];
					r[1]++;
					xa[r[1]].z=mm;
					xa[r[1]].i=xc[r[3]].i;
				}
				else {
					mm=m[xc[r[3]].i][2];
					r[2]++;
					xb[r[2]].i=xc[r[3]].i;
				}
				r[3]--;
			}
		}
		for(int i=1;i<=r[1];i++)	sum+=xa[i].z;
		for(int i=1;i<=r[2];i++)	sum+=xb[i].z;
		for(int i=1;i<=r[3];i++)	sum+=xc[i].z;
		cout<<sum<<endl;
	}
	return 0;
}