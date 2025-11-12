#include<bits/stdc++.h>
using namespace std;
int more[100000+5]={-999999};
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	int a[10000+5][4],amax[10000+5],maxp[10000+5];
	for(int i=1;i<=n;i++)
		{
			a[i][1]=0;a[i][2]=0;a[i][3]=0;
			amax[i]=0;
			maxp[i]=0;
			more[i]=-1e8;
		}
	while(t)
	{
		int suma=0,sumb=0,sumc=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			amax[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			if(amax[i]==a[i][1])
			{
				maxp[i]=1;
				suma++;
			}
			else if(amax[i]==a[i][2])
			{
				maxp[i]=2;
				sumb++;
			}
			else if(amax[i]==a[i][3])
			{
				sumc++;
				maxp[i]=3;
			}
			ans+=amax[i];
		}
		if(suma>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(maxp[i]==1)
				{
					more[i]=max(a[i][2],a[i][3])-amax[i];
		//			cout<<"!1";
				}
			}
	//		cout<<"*";
			sort(more+1,more+n+1,cmp);
		//	cout<<")";
			int j=1;
			for(int i=suma;i>n/2;i--)
			{
				ans+=more[j];
				j++;
		//		cout<<"@";
			}
		}
		else if(sumb>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(maxp[i]==2)
				{
		//			cout<<"!2";
					more[i]=max(a[i][1],a[i][3])-amax[i];
				}
			}
			sort(more+1,more+n+1,cmp);
			int j=1;
			for(int i=sumb;i>n/2;i--)
			{
				ans+=more[j];
				j++;
		//		cout<<"@";
			}
		}
		
		else if(sumc>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(maxp[i]==3)
					{
		//				cout<<"!3";
						more[i]=max(a[i][2],a[i][1])-amax[i];
					}
			}
			sort(more+1,more+n+1,cmp);
			int j=1;
			for(int i=sumc;i>n/2;i--)
			{
				ans+=more[j];
				j++;
		//		cout<<"@";
			}
		}
		cout<<ans<<endl;
		t--;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=0;a[i][2]=0;a[i][3]=0;
			amax[i]=0;
			maxp[i]=0;
			more[i]=-1e8;
		}
		if(t!=0)
			cin>>n;
	}
	
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1


0 1 0 0 1 0 0 2 0 0 2 0
*/
