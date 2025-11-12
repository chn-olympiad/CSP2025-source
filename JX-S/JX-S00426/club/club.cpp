#include <bits/stdc++.h>
using namespace std;
int T;
int n;
struct people{
	int q;
	int w;
	int e;
	int cma;
}a[100010];
int d1[100010];
int d2[100010];
int d3[100010];
int d[4];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>T;
while(T--){
	cin>>n;
	d[1]=0;
	d[2]=0;
	d[3]=0;
	int k=n/2;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].q>>a[i].w>>a[i].e;
		if(a[i].q>=a[i].w)
		{
			if(a[i].w>=a[i].e)
			{
			d[1]++;
			a[i].cma=a[i].q-a[i].w;
			d1[d[1]]=a[i].cma;
			sum+=a[i].q;
			}
			else if(a[i].q>=a[i].e)
			{
				d[1]++;
				a[i].cma=a[i].q-a[i].e;
				d1[d[1]]=a[i].cma;
				sum+=a[i].q;
			}else
			{
				d[3]++;
				a[i].cma=a[i].e-a[i].q;
				d3[d[3]]=a[i].cma;
				sum+=a[i].e;
			}
		}
		else if(a[i].w>=a[i].e)
		{
			if(a[i].q>=a[i].e)
			{
				d[2]++;
				a[i].cma=a[i].w-a[i].q;
				d2[d[2]]=a[i].cma;
				sum+=a[i].w;
			}else
			{
				d[2]++;
				a[i].cma=a[i].w-a[i].e;	
				d2[d[2]]=a[i].cma;
				sum+=a[i].w;
			}
		}else
		{
		d[3]++;
		a[i].cma=a[i].e-a[i].w;	
		d3[d[3]]=a[i].cma;
		sum+=a[i].e;
		}	
	}
	if(d[1]>k)
	{
	sort(d1+1,d1+1+d[1],cmp);	
	for(int i=k+1;i<=d[1];i++)
	{
		sum-=d1[i];
	}
	}
	else if(d[2]>k){
	sort(d2+1,d2+1+d[2],cmp);
	for(int i=k+1;i<=d[2];i++)
	{
		sum-=d2[i];
	}
	}
	else if(d[3]>k){
	sort(d3+1,d3+1+d[3],cmp);
	for(int i=k+1;i<=d[3];i++)
	{
		sum-=d3[i];
	}
	}
	cout<<sum<<endl;
}
return 0;
}
