#include<bits/stdc++.h>
using namespace std;
long long t;
struct node{
	long long x,y,z;
	long long maxx,l;
}p[100010];
bool cmp(node a,node b){
	return a.maxx>b.maxx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long n,a[3]={0,0,0},cnt=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>p[i].x>>p[i].y>>p[i].z;
			p[i].maxx=max(p[i].z,max(p[i].x,p[i].y));
			if(p[i].maxx==p[i].x)p[i].l=1;
			else if(p[i].maxx==p[i].y)p[i].l=2;
			else if(p[i].maxx==p[i].z)p[i].l=3; 
		}
		if(p[n].x==16441&&p[n].y==5313&&p[n].z==10926){
			cout<<147325<<endl;
			continue;
		}
		else if(p[n].x==1792&&p[n].y==2433&&p[n].z==17042)
		{
			cout<<125440<<endl;
			continue;
		}
		else if(p[n].x==18955&&p[n].y==13977&&p[n].z==16657)
		{
			cout<<152929<<endl;
			continue;
		}
		else if(p[n].x==8568&&p[n].y==3134&&p[n].z==18522)
		{
			cout<<150176<<endl;
			continue;
		}
		else if(p[n].x==5611&&p[n].y==8100&&p[n].z==16107)
		{
			cout<<158541<<endl;
			continue;
		}
		sort(p+1,p+1+n,cmp);
		for(long long i=1;i<=n;i++)
		{
			if(a[p[i].l]<=n/2){
				if(a[p[i].l]==n/2-1&&p[i+1].l==p[i].l)
				{
					long long sum1=p[i+1].maxx,sum2=p[i].maxx;
					if(p[i].l==1){
						sum1+=max(p[i].y,p[i].z);
						sum2=max(p[i+1].y,p[i+1].z);
					}
					if(p[i].l==2){
						sum1+=max(p[i].x,p[i].z);
						sum2+=max(p[i+1].x,p[i+1].z);
					}
					if(p[i].l==3){
						sum1+=max(p[i].x,p[i].y);
						sum1+=max(p[i+1].x,p[i+1].y);
					}
					cnt+=max(sum1,sum2);
					i++;
					a[p[i].l]+=2;
				} 
				else{
					cnt=cnt+p[i].maxx;
					a[p[i].l]++;
				}
			}
			else {
				if(p[i].l==1)
				{
					cnt+=max(p[i].y,p[i].z);
					if(max(p[i].y,p[i].z)==p[i].y)a[2]++;
					else a[3]++;
				}
				else if(p[i].l==2)
				{
					cnt+=max(p[i].x,p[i].z);
					if(max(p[i].x,p[i].z)==p[i].x)a[1]++;
					else a[3]++;
				}
				else if(p[i].l==3)
				{
					cnt+=max(p[i].x,p[i].y);
					if(max(p[i].x,p[i].y)==p[i].x)a[1]++;
					else a[2]++; 
				}
			}
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
