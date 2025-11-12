#include<bits/stdc++.h>
using namespace std;
long long n,x,a[500005][25],k[25],xb[500005][20],g[20],qz[500005][20],s;
int o;
void pd(int xx,int yy){
	bool f=1;
	for(int i=2;i<=20;i++)
	{
		if((qz[yy][i]-qz[xx-1][i])%2!=k[i])
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		s++;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	while(x)
	{
		o++;
		if(x&1) k[o]=1;
		x>>=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		o=0;
		while(x)
		{
			o++;
			if(x&1) a[i][o]=1;
			x>>=1;
		}
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			qz[j][i]=qz[j-1][i];
			if(a[j][i]) xb[++g[i]][i]=j,qz[j][i]++;
		}
		xb[g[i]+1][i]=n+1,qz[n+1][i]=qz[n][i];
	}
	for(int i=k[1];i<=20;i+=2)
	{
		if(i==0)
		{
			for(int j=1;j<=g[1];j++)
			{
				for(int xx=xb[j-1][1]+1;xx<=xb[j][1]-1;xx++)
				{
					for(int yy=xb[j-1][1]+1;yy<=xx;yy++)
					{
						pd(xx,yy);
					}
				}
			}
		}
		else
		{
			for(int j=1;j<=g[1]-i+1;j++)
			{
				for(int xx=xb[j-1][1]+1;xx<=xb[j][1]-1;xx++)
				{
					for(int yy=xb[j+i-1][1]+1;yy<=xb[j+i][i]-1;yy++)
					{
						pd(xx,yy);
					}
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
