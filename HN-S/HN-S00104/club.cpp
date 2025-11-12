#include<bits/stdc++.h>//样例过了 
long long n,t;
long long hf;
long long hg[10010][10];
long long num[10];
long long maxx;
using namespace std;
void ss(long long k,long long newmaxx) //k为从上至下的第k组，maxx为要求的最大值，num为当前组数已有人数 
{
	if(num[1]>hf||num[2]>hf||num[3]>hf) return ;
	if(k-1>n) return ;
	maxx=max(maxx,newmaxx);
	for(int i=1;i<=3;i++)
	{
		num[i]++;
		ss(k+1,newmaxx+hg[k][i]);
		num[i]--;
	}
}
int big(long long x,long long y,long long z)
{
	long long yig=max(max(x,y),max(x,z));
	return max(yig,max(y,z));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxx=0;
		cin>>n;
		hf=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>hg[i][1]>>hg[i][2]>>hg[i][3];
		}
		if(n>15)
		{
			for(int i=1;i<=n;i++)
			{
				maxx+=big(hg[i][1],hg[i][2],hg[i][3]);
			}
		}
		else
		{
			ss(1,0);
		}
		cout<<maxx<<endl;
	}
	return 0;
} 
