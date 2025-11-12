#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int cnt;
int yh1[9999999]={0},yh[9999999]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=1;
	while(i<=n)
	{
		if(a[i]==k)
		{
			cnt++;
		}
		else {
			int da=0;
			yh1[9999999]={0};
			yh[9999999]={0};
			int un=0;
			int ma=a[i];
			while(ma)
			{
				un++;
				yh[un]=ma%2;
				ma/=2;
			}
			int si=un;
			i++;
			int jl=i;
			while(i<=n)
			{
				un=0;
				ma=a[i];
				if(ma==0)yh[1]=0;
				else
				{
					while(ma)
					{
						un++;
						yh1[un]=ma%2;
						ma/=2;
					}
					int mm=0;
					if(si>un)
					{
						for(int j=1;j<=un;j++)
						{
							if(yh[j]!=yh1[j])yh[j]=0;
						}
						for(int j=si;j>=1;j--)
						{
							mm=mm*2+yh[j];
						} 
					}
					else
					{
						for(int j=1;j<=si;j++)
						{
							if(yh[j]!=yh1[j])yh1[j]=0;
						}
						for(int j=un;j>=1;j--)
						{
							yh[j]=yh1[j];
							mm=mm*2+yh[j];
						} 
						si=un;
					}
					if(mm==k)
					{
						da=1;
						break;
					}
					
				}
				i++;
			}
			if(da==1)cnt++;
			else i=jl+1;
		}
		i++;
	}
	cout<<cnt;
}
