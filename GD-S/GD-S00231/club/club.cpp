#include<bits/stdc++.h>
using namespace std;
int maxx(int a1,int a2,int a3)
{
	if(a1>=a2&&a1>=a3)
	{
		return 1;
	}
	else return a2>a3?2:3;
}

struct str{
	int club[4];
	int flag=0;
}dent[200100];
struct uct{
	int ai;
	int xuehao;
}c[4][100100];
bool cmp1(uct a1,uct a2)
{
	return a1.ai>a2.ai;
}
int n,ans=0,t;
int main()
{
	
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	for(int ci=1;ci<=t;ci++)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			cin>>dent[i].club[j];
			
			 dent[i].flag=maxx(dent[i].club[1],dent[i].club[2],dent[i].club[3]);
		}
		int l[4]={1,1,1,1};
		for(int i=1;i<=n;i++)
		{
			
			int won=dent[i].flag;
			if(dent[i].club[won]==0)
			break;
			ans+=dent[i].club[won];
			if(l[won]>n/2)
			{
				//cout<<"chu"<<endl;
				int k=n/2;
				bool bo=0;
				for( ;k>0;k--)
				{
					str lin=dent[k];lin.club[lin.flag]=-1;
				//	cout<<lin.flag<<endl;&&dent[i].club[won]<dent[k].club[dent[k].flag]
					lin.flag=maxx(lin.club[1],lin.club[2],lin.club[3]);
					if(l[lin.flag]<=n/2&&(lin.club[lin.flag]+dent[i].club[won]>dent[k].club[dent[k].flag]))
					{
					
						
							c[lin.flag][l[lin.flag]].ai=lin.club[lin.flag];
							c[lin.flag][l[lin.flag]].xuehao=k;
							l[lin.flag]++;
							ans=ans+lin.club[lin.flag]-dent[k].club[dent[k].flag];
							//ans=ans-dent[k].club[dent[k].flag];
							//l[lin.flag]++;
								str lin1=dent[k];
							dent[k]=dent[i];
							sort(c[won]+1,c[won]+n/2,cmp1);
							sort(c[lin.flag]+1,c[lin.flag]+l[lin.flag],cmp1);
							bo=1;
							break;
				
					}
				/*	else{
						lin.club[lin.flag]=-1;
					lin.flag=maxx(lin.club[1],lin.club[2],lin.club[3]);
					if()
					}*/
				}
				if(bo==0){
				c[won][l[won]].ai=dent[i].club[won];
				sort(c[won]+1,c[won]+l[won]+1,cmp1);
				ans-=c[won][l[won]].ai;
				int i1=c[won][l[won]].xuehao;
				for(int j=1;j<=3;j++)
				{
					dent[i+n].club[j]=dent[i1].club[j];
				}
				dent[i+n].club[won]=-1;
				dent[i+n].flag=maxx(dent[i+n].club[1],dent[i+n].club[2],dent[i+n].club[3]);
				n++;
				//l[won]--;
				}
			}
			else
			{
				c[won][l[won]].ai=dent[i].club[won];
				c[won][l[won]].xuehao=i;
				l[won]++;
				sort(c[won]+1,c[won]+l[won],cmp1); 
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
