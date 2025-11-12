#include<bits/stdc++.h>
using namespace std;
int s1[100010],s2[100010],s3[100010],c[100010];
struct bj
{
	int e,d,max,mn;
};
bj sz[100010];
int cmp1(int a,int b) 
{
	return a>b;
}
int cmp2(bj a,bj b) 
{
	return a.max>b.max;
}
int cmp3(bj a,bj b) 
{
	return a.e>b.e;
}
int cmp4(bj a,bj b) 
{
	return a.d>b.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		int n=0,m=0,ss1=0,ss2=0,ss3=0,an=0;
		int td=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>s1[i]>>s2[i]>>s3[i];
			sz[i].e=c[i]=s2[i]-s1[i];
			sz[i].d=s3[i]-s1[i];
			if(sz[i].e>=sz[i].d)
			{
				sz[i].max=sz[i].e;
				sz[i].mn=2;
			}
			else
			{
				sz[i].max=sz[i].d;
				sz[i].mn=3;
			}
			ss1+=s1[i];ss3+=s3[i]; 
		}
		if(ss3==0)
		{
			sort(c+1,c+1+n,cmp1);
			for(int i=1;i<=m;i++)
			{
				ss1+=c[i];
			}
			an=ss1;
		}
		else	{
			sort(sz+1,sz+1+n,cmp2);
			int i=1;
			for(i=1;i<=n;i++)
			{
				
				ss1+=sz[i].max;
		//		cout<<ss1<<' ';
//				cout<<sz[i].max<<' '<<sz[i].mn<<"hggg";
			//	cout<<"u";
				sz[i].max=-99999;
				if(sz[i].mn==2)
				{
					sz[i].e=-99999;
					s2[0]++;

				}
				else
				{
					sz[i].d=-99999;
					s3[0]++;
				}
				if(sz[i+1].max<=0&&i>=m)
				{
					td=1;
					break;
				}
				if(s3[0]>=m||s2[0]>=m) break;
			}
			if(td==1||i==n)
			{
				cout<<td+10000000<<' ';
				an=ss1;
			}
			else if	(s3[0]==m)
			{
	//			cout<<"u";
				sort(sz+1,sz+1+n,cmp3);
				i=n-i;
				for(int k=1;k<=i;k++)
				{
					if(sz[k].e<=0) break;
					ss1+=sz[k].e;
				}
				an=ss1;
			}
			else
			{
		//		cout<<"g";
				sort(sz+1,sz+1+n,cmp4);
				i=n-i;
				for(int k=1;k<=i;k++)
				{
					if(sz[k].d<=0) break;
					ss1+=sz[k].d;
				}
				an=ss1;
			}
		}
		cout<<an<<endl;	
		for(int i=0;i<=n;i++)
		{
			sz[i].mn=sz[i].e=sz[i].max=sz[i].d=c[i]=s1[i]=s2[i]=s3[i]=0;
		}
	}	
	return 0;
}
	
