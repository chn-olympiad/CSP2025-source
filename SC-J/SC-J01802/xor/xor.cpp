#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int w=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
    {
	    w=-1;
		ch=getchar();     	
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int n,k,a[500005],dz,t=0,dj,ans;
struct node{
	int x;
	int y;
} e[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	} 
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			t++;
			e[t].x=i;
			e[t].y=i;
			continue;	
		}
		dz=a[i];
		for(int j=i+1;j<=n;j++)
		{
			dz=dz^a[j];
			if(dz==k)
			{
				t++;
				e[t].x=i;
				e[t].y=j;
				break;
			}
		}
    }
	for(int i=1;i<=t;i++)
	{
		if(e[i].x<=dj)
		{
			continue;
		}
		else
		{
			dj=e[i].y;
			ans++; 
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 