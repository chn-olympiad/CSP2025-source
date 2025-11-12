#include<bits/stdc++.h>
using namespace std;

struct note{
	int a;
	int i;
};

int w[100005]={};
int a[4][100005];
vector<note> q[4];
int miaa=9999999,miab=9999999,miac=9999999;
int minn[4];

int findd(int x,int zi)
{
	int ma=-1,mai,mai2;
	for(int i=1;i<=3;i++)
	{
		if(a[i][x]>ma)
		{
			ma=a[i][x];
			mai=i;
		}
	}
	if(zi==1)
	{
		return mai;
	}
	else
	{
		ma=0;
		for(int i=1;i<=3;i++)
		{
			if(i==mai)
			{
				continue;
			}
			else if(a[i][x]>=ma)
			{
				ma=a[i][x];
				mai2=i;
			}
		}
		return mai2;
	}
}

void finm()
{
	miaa=99999999999;
	miab=99999999999;
	miac=99999999999;
	if(q[1].size()==0)
	{
		minn[1]=0;
	}
	for(int i=0;i<q[1].size();i++)
	{
		if(miaa>q[1][i].a)
		{
			miaa=q[1][i].a;
			minn[1]=i;
		}
	}
	if(q[2].size()==0)
	{
		minn[2]=0;
	}
	for(int i=0;i<q[2].size();i++)
	{
		if(miab>q[2][i].a)
		{
			miab=q[2][i].a;
			minn[2]=i;
		}
	}
	if(q[2].size()==0)
	{
		minn[3]=0;
	}
	for(int i=0;i<q[3].size();i++)
	{
		if(miac>q[3][i].a)
		{
			miac=q[3][i].a;
			minn[3]=i;
		}
	}
}

void dh(int x,int l)
{
	finm();
	if(minn[l]==0 || minn[l]==-1)
	{
		for(int i=0;i<q[w[x]].size();i++)
		{
			if(q[w[x]][i].i==x)
			{
				q[w[x]][i].a=0;
				q[w[x]][i].i=-1;
			}	
		}
		q[l].push_back({a[l][x],x});
		return ;
	}
	int y=minn[l];
	if(a[w[x]][y]+a[w[y]][x]<a[w[x]][x]+a[w[y]][y])
	{
		return ;
	}
	for(int i=0;i<q[w[x]].size();i++)
	{
		if(q[w[x]][i].i==x)
		{
			q[w[x]][i].a=a[w[x]][y];
			q[w[x]][i].i=y;
			}	
	}
	for(int i=0;i<q[w[y]].size();i++)
	{
		if(q[w[y]][i].i==y)
		{
			q[w[y]][i].a=a[w[y]][x];
			q[w[y]][i].i=x;
			}	
	}
	int xx=w[x];
	w[x]=w[y];
	w[y]=xx;
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ans=0;
	int t;
	int n;
	cin>>t;
	while(t){
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		memset(w,0,sizeof(w));
		cin>>n;		
		ans=0;
		int maxn=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i];
			cin>>a[2][i];
			cin>>a[3][i];
		}
		
		//‘§¥¶¿Ì 
		for(int i=1;i<=n;i++)
		{
			int s=findd(i,1);
			if(q[s].size()>maxn-1)
			{
				s=findd(i,2);
			}
			w[i]=s;
			q[s].push_back((note){a[s][i],i});
		}

		for(int i=1;i<=3;i++)
		{
			for(int l=0;l<q[i].size();l++)
			{
			//	cout<<q[i][l].a<<" ";
				ans=ans+q[i][l].a;
			}
		//	cout<<endl;
		}
		
		
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=3;l++)
			{
				if(w[i]==w[l])
				{
					continue;
				}
				dh(i,l);
			}
		 } 
		 
		 
	//	cout<<endl<<" !! "<<endl;
		int ans2=0;
		for(int i=1;i<=3;i++)
		{
			for(int l=0;l<q[i].size();l++)
			{
				cout<<q[i][l].a<<" ";
				ans2=ans2+q[i][l].a;
			}
			cout<<endl;
		}
		cout<<max(ans,ans2)<<endl;
		t--;
	}
	return 0;
 } 
 
 
 
/*

3
4  
4 2  1 
3 2  4 
5 3 4 
3 5 1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0 
2 
10 9 8 
4 0 0 
*/ 
