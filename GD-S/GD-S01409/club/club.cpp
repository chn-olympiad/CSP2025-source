#include<bits/stdc++.h>
using namespace std;
long long T,n,sum[5],ans,k[5];
struct sj{
	long long a,b,c,maxv;	
}m[200005];
bool cmp(sj x,sj y)
{
	if(x.maxv>y.maxv)
	{
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		memset(m,0,sizeof(m));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>=m[i].b)
			{
				m[i].maxv=m[i].a;
			}
			else {
				m[i].maxv=m[i].b;
			}
			if(m[i].c>=m[i].maxv)
			{
				m[i].maxv=m[i].c;
			}
		}
		sort(m+1,m+1+n,cmp);
//_______________________Êä³ö__________________________
		for(int i=1;i<=n;i++)
		{
			memset(k,0,sizeof(k));
			if(m[i].a==m[i].maxv)
			{
				k[1]=1;
			}
			if(m[i].b==m[i].maxv)
			{
				k[2]=1;
			}
			if(m[i].c==m[i].maxv)
			{
				k[3]=1;
			}
			if(k[1]==1)
			{
				if(sum[1]<n/2)
				{
					ans+=m[i].a;
					sum[1]++; 
				}
				else{
					if(m[i].b>m[i].c)
					{
						ans+=m[i].b;
						sum[2]++;
					}
					else{
						ans+=m[i].c;
						sum[3]++;
					}
				}
				continue;
			}
			if(k[2]==1)
			{
				if(sum[2]<n/2)
				{
					ans+=m[i].b;
					sum[2]++; 
				}
				else{
					if(m[i].a>m[i].c)
					{
						ans+=m[i].a;
						sum[1]++;
					}
					else{
						ans+=m[i].c;
						sum[3]++;
					}
				}
				continue;
			}
			if(k[3]==1)
			{
				if(sum[3]<n/2)
				{
					ans+=m[i].c;
					sum[3]++; 
				}
				else{
					if(m[i].b>m[i].a)
					{
						ans+=m[i].b;
						sum[2]++;
					}
					else{
						ans+=m[i].a;
						sum[1]++;
					}
				}
				continue;
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
//3
//4
//4 2 1
//3 2 4 
//5 3 4
//3 5 1
//4 
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

