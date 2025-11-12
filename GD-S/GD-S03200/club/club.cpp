#include<bits/stdc++.h>
using namespace std;
int G,n,a[100010][4],sn[4],s;
int mk,kt[4][100010],d[100010];
void csh()
{
	sn[1]=0; sn[2]=0; sn[3]=0;
	s=0;
	memset(a,0,sizeof(a));
	memset(kt,0,sizeof(kt));
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>G;
	while(G--)
	{
		cin>>n;
		csh();
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mx==a[i][1]){
				kt[1][++sn[1]]=i;
				s+=a[i][1];
			}
			else if(mx==a[i][2]){
				kt[2][++sn[2]]=i;
				s+=a[i][2];
			}
			else{
				kt[3][++sn[3]]=i;
				s+=a[i][3];
			}
		}
		mk=1;		
		if(sn[mk]<sn[2]) mk=2;
		if(sn[mk]<sn[3]) mk=3;
		if(sn[mk]<=(n/2)){
			cout<<s<<"\n";
			continue;
		}
		else{
			for(int i=1;i<=sn[mk];++i)
			{
				int k=kt[mk][i],kl[3]={1,2,3};
				
				for(int l=0;l<2;l++)
					for(int j=1;j>=l;j--)
					{
						if(a[k][kl[j]]<a[k][kl[j+1]]) swap(kl[j],kl[j+1]);
					}
				
				d[i]=a[k][kl[0]]-a[k][kl[1]];
				
//				cout<<" _"<<k<<" : "<<kl[0]<<" "<<kl[1]<<" "<<kl[2]<<" #"<<d[i]<<" \n";
				
			}
			//sort(d+1,d+sn[mk]+1,px);   //(为什么不可以这样打？！！！ 
			for(int i=sn[mk]-1;i;--i)
				for(int j=i;j<sn[mk];++j)
					if(d[j]<d[j+1]) swap(d[j],d[j+1]);
			
			
			for(int i=sn[mk];i>(n/2);i--)
			{
				s-=d[i];
			}
			
			cout<<s<<"\n";
		}
	}
	return 0;
} 
//一年没码东西结果啥都忘光了 \(.0 ^ 0.)/ 
//不是这东西 n方 能过嘛？！ 

