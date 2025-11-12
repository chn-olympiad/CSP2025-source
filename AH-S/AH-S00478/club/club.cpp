#include <bits/stdc++.h>
using namespace std;
long long zu,n,a[100005][10],ren[10],myd,hui,x;
void pd()
{
	if(ren[1]<=n/2 && ren[2]<=n/2 && ren[3]<=n/2)
	{
		cout<<myd;
		hui=1;
		return;
	}
	long long zuishao=99999,wei=0,huan=0;
	if(ren[1]>n/2)
	{
		for(int i=0;i<ren[1]-n/2;i++)
		{
			zuishao=99999,wei=0,huan=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][8]==1)
				{
					if(a[i][5]==1)
					{
						zuishao=min(zuishao,a[i][0]-a[i][6]);
						if(zuishao==a[i][0]-a[i][6])
						{
							wei=i;
							huan=a[i][7];
						}
					}
					else if(a[i][7]==1)
					{
						if(max(a[i][5],a[i][7])==3 && min(a[i][5],a[i][7])==1) x=2;
						else if(max(a[i][5],a[i][7])==2 && min(a[i][5],a[i][7])==1) x=3;
						else x=1;
						a[i][9]=x;
						zuishao=min(zuishao,a[i][6]-a[i][x]);
						if(zuishao==a[i][6]-a[i][x]) 
						{
							wei=i;
							huan=x;
						}
					}
				}
			}
			myd=myd-zuishao;
			cout<<wei<<" "<<a[wei][8]<<huan<<endl;//
			a[wei][8]=huan;
		}
		ren[1]=n/2;
		void pd();
	}
	if(ren[2]>n/2)
	{
		for(int i=0;i<ren[2]-n/2;i++)
		{
			zuishao=99999,wei=0,huan=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][8]==2)
				{
					if(a[i][5]==2)
					{
						zuishao=min(zuishao,a[i][0]-a[i][6]);
						if(zuishao==a[i][0]-a[i][6])
						{
							wei=i;
							huan=a[i][7];
						}
					}
					else if(a[i][7]==2)
					{
						if(max(a[i][5],a[i][7])==3 && min(a[i][5],a[i][7])==1) x=2;
						else if(max(a[i][5],a[i][7])==2 && min(a[i][5],a[i][7])==1) x=3;
						else x=1;
						a[i][9]=x;
						zuishao=min(zuishao,a[i][6]-a[i][x]);
						if(zuishao==a[i][6]-a[i][x]) 
						{
							wei=i;
							huan=x;
						}
					}
				}
			}
			myd=myd-zuishao;
			cout<<wei<<" "<<a[wei][8]<<huan<<endl;//
			a[wei][8]=huan;
		}
		ren[2]=n/2;
		void pd();
	}
	if(ren[3]>n/2)
	{
		
		for(int i=0;i<ren[3]-n/2;i++)
		{
			zuishao=99999,wei=0,huan=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][8]==3)
				{
					if(a[i][5]==3)
					{
						zuishao=min(zuishao,a[i][0]-a[i][6]);
						if(zuishao==a[i][0]-a[i][6])
						{
							wei=i;
							huan=a[i][7];
						}
					}
					else if(a[i][7]==3)
					{
						if(max(a[i][5],a[i][7])==3 && min(a[i][5],a[i][7])==1) x=2;
						else if(max(a[i][5],a[i][7])==2 && min(a[i][5],a[i][7])==1) x=3;
						else x=1;
						a[i][9]=x;
						zuishao=min(zuishao,a[i][6]-a[i][x]);
						if(zuishao==a[i][6]-a[i][x]) 
						{
							wei=i;
							huan=x;
						}
					}
				}
			}
			myd=myd-zuishao;
			cout<<wei<<" "<<a[wei][8]<<huan<<endl;//
			a[wei][8]=huan;
		}
		ren[3]=n/2;
		void pd();
	}
	if(ren[1]<=n/2 && ren[2]<=n/2 && ren[3]<=n/2 && hui!=1)
	{
		cout<<myd;
		hui=1;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>zu;
	for(int i=0;i<zu;i++)
	{
		for(int j=0;j<10;j++) ren[j]=0;
		myd=0;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			a[j][0]=max(a[j][1],a[j][2]);
			a[j][0]=max(a[j][0],a[j][3]);
			if(a[j][1]==a[j][0])
			{
				a[j][5]=1;
				a[j][6]=max(a[j][2],a[j][3]);
			}
			else if(a[j][2]==a[j][0])
			{
				a[j][5]=2;
				a[j][6]=max(a[j][1],a[j][3]);
			}
			else 
			{
				a[j][5]=3;
				a[j][6]=max(a[j][1],a[j][2]);
			}
			if(a[j][1]==a[j][6]) a[j][7]=1;
			else if(a[j][2]==a[j][6]) a[j][7]=2;
			else a[j][7]=3;
			myd=myd+a[j][0];
			ren[a[j][5]]++;
			a[j][8]=a[j][5];
		}
		if(ren[1]<=n/2 && ren[2]<=n/2 && ren[3]<=n/2)
		{
			cout<<myd;
		}
		else 
		{
			pd();
		}
		cout<<endl;
	}
	return 0;
}
