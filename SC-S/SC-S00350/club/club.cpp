#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define ll long long
#define rint register int

using namespace std;
using namespace __gnu_pbds;


const int N=1e5+10;
int t,n;

struct node
{
	int x,y,z;
}arr[N];

int tmp12[N],tmp13[N],tmp21[N],tmp23[N],tmp31[N],tmp32[N];

int read()
{
	int k=0,f=1;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	
	while('0'<=c&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	
	return k*f;
}

void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x; 
	}
	
	if(x<10)
	{
		putchar(x+'0');
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
	
}

bool cmp12(int a,int b)
{
	return arr[a].x-arr[a].y<arr[b].x-arr[b].y;
}

bool cmp13(int a,int b)
{
	return arr[a].x-arr[a].z<arr[b].x-arr[b].z;
}

bool cmp21(int a,int b)
{
	return arr[a].y-arr[a].x<arr[b].y-arr[b].x;
}

bool cmp23(int a,int b)
{
	return arr[a].y-arr[a].z<arr[b].y-arr[b].z;
}

bool cmp31(int a,int b)
{
	return arr[a].z-arr[a].x<arr[b].z-arr[b].x;
}

bool cmp32(int a,int b)
{
	return arr[a].z-arr[a].y<arr[b].z-arr[b].y;
}

int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	
	while(t--)
	{
		n=read();
		
		int idx1=0,idx2=0,idx3=0;
		ll ans=0;
		for(rint i=1;i<=n;++i)
		{
			arr[i].x=read(),arr[i].y=read(),arr[i].z=read();
			
			int maxn=max({arr[i].x,arr[i].y,arr[i].z});
			
			if(maxn==arr[i].x)
			{
				tmp12[++idx1]=i;
				tmp13[idx1]=i;
			}
			else if(maxn==arr[i].y)
			{
				tmp21[++idx2]=i;
				tmp23[idx2]=i;
			}
			else
			{
				tmp31[++idx3]=i;
				tmp32[idx3]=i;
			}
			
			ans=1ll*maxn+ans;
		}
		
		
		if(idx1<=n/2&&idx2<=n/2&&idx3<=n/2)
		{
			write(ans);
			putchar('\n');
			continue;
		}
		
		if(idx1>n/2)
		{
			sort(tmp12+1,tmp12+idx1+1,cmp12);
			sort(tmp13+1,tmp13+idx1+1,cmp13);
			
			int id12=1,id13=1;
			gp_hash_table<int,bool> mp;
			
			while(idx1>n/2)
			{
				while(mp[tmp12[id12]])
				{
					++id12;
				}
				while(mp[tmp13[id13]])
				{
					++id13;
				}
				
				if(arr[tmp12[id12]].x-arr[tmp12[id12]].y<arr[tmp13[id13]].x-arr[tmp13[id13]].z)
				{
					ans-=arr[tmp12[id12]].x-arr[tmp12[id12]].y;
					mp[tmp12[id12]]=1;
				}
				else
				{
					ans-=arr[tmp13[id13]].x-arr[tmp13[id13]].z;
					mp[tmp13[id13]]=1;
				}
				--idx1;
			}
		}
		
		else if(idx2>n/2)
		{
			sort(tmp21+1,tmp21+idx2+1,cmp21);
			sort(tmp23+1,tmp23+idx2+1,cmp23);
			
			int id21=1,id23=1;
			gp_hash_table<int,bool> mp;
			
			while(idx2>n/2)
			{
				while(mp[tmp21[id21]])
				{
					++id21;
				}
				while(mp[tmp23[id23]])
				{
					++id23;
				}
				
				if(arr[tmp21[id21]].y-arr[tmp21[id21]].x<arr[tmp23[id23]].y-arr[tmp23[id23]].z)
				{
					ans-=arr[tmp21[id21]].y-arr[tmp21[id21]].x;
					mp[tmp21[id21]]=1;
				}
				else
				{
					ans-=arr[tmp23[id23]].y-arr[tmp23[id23]].z;
					mp[tmp23[id23]]=1;
				}
				--idx2;
			}
		}
		
		else
		{
			sort(tmp31+1,tmp31+idx3+1,cmp31);
			sort(tmp32+1,tmp32+idx3+1,cmp32);
			
			int id31=1,id32=1;
			gp_hash_table<int,bool> mp;
			
			while(idx3>n/2)
			{
				while(mp[tmp31[id31]])
				{
					++id31;
				}
				while(mp[tmp32[id32]])
				{
					++id32;
				}
				
				if(arr[tmp31[id31]].z-arr[tmp31[id31]].x<arr[tmp32[id32]].z-arr[tmp32[id32]].y)
				{
					ans-=arr[tmp31[id31]].z-arr[tmp31[id31]].x;
					mp[tmp31[id31]]=1;
				}
				else
				{
					ans-=arr[tmp32[id32]].z-arr[tmp32[id32]].y;
					mp[tmp32[id32]]=1;
				}
				--idx3;
			}
		}
		
		write(ans);
		putchar('\n');
	}
	
	return 0;
}