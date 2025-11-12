#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,c;
struct str
{
	int z,in,num;
}mem[200005];
bool vis[100005];
bool cmp(str a,str b)
{
	return a.z>b.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int per[3]={},ans=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			scanf("%d %d %d",&a,&b,&c);
			ans+=a;
			mem[2*i-1].z=b-a;
			mem[2*i-1].in=1;
			mem[2*i-1].num=i;
			mem[2*i].z=c-a;
			mem[2*i].in=2;
			mem[2*i].num=i;
		}
		sort(mem+1,mem+2*n+1,cmp);
		//for(int i=1;i<=2*n;i++)
		//	cout<<mem[i].in<<" "<<mem[i].num<<" "<<mem[i].z<<endl;
		for(int i=1;i<=2*n;i++)
		{
			int z=mem[i].z,in=mem[i].in,num=mem[i].num;
			if(per[1]+per[2]>=n/2&&z<=0)
				break;
			if((!vis[num])&&per[in]<n/2)
			{
				vis[num]=1;
				per[in]++;
				ans+=z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	
