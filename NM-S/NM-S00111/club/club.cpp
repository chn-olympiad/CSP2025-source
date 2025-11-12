#include<bits/stdc++.h>
using namespace std;
struct hu
{
	int aval;
	int aie;
	int bval;
	int bie;
	int cval;
	int cie;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int answer[t];
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		hu peo[n];
		for(int j=0;j<n;j++)
		{
			cin>>peo[j].aval;
			cin>>peo[j].bval;
			cin>>peo[j].cval;
			peo[j].aie=0;
			peo[j].bie=0;
			peo[j].cie=0;
		}
		int a=0;
		int b=0;
		int c=0;
		for(int j=0;j<n;j++)
		{
			if(peo[j].aval>=peo[j].bval)
			{
				if(peo[j].aval>=peo[j].cval)
				{
					peo[j].aie=1;
					a++;
				}
				else
				{
					peo[j].cie=1;
					c++;
				}
			}
			else
			{
				if(peo[j].bval>=peo[j].cval)
				{
					peo[j].bie=1;
					b++;
				}
				else
				{
					peo[j].cie=1;
					c++;
				}
			}
		}
		int ma;
		int cha[n];
		int mincha=INT_MAX;
		int qwer;
		while(a>n/2)
		{
			mincha=INT_MAX;
			for(int j=0;j<n;j++)
			{
				if(peo[j].aie==1)
				{
					ma=max(peo[j].bval,peo[j].cval);
					cha[j]=peo[j].aval-ma;
					if(cha[j]<mincha)
					{
						mincha=cha[j];
						qwer=j; 
					}
				}
			}
			peo[qwer].aie=0;
			a--; 
			if(peo[qwer].bval>=peo[qwer].cval)
			{
				peo[qwer].bie=1;
				b++;
			}
			else
			{
				peo[qwer].cie=1;
				c++;
			}
		}
		while(b>n/2)
		{
			mincha=INT_MAX;
			for(int j=0;j<n;j++)
			{
				if(peo[j].bie==1)
				{
					ma=max(peo[j].aval,peo[j].cval);
					cha[j]=peo[j].bval-ma;
					if(cha[j]<mincha)
					{
						mincha=cha[j];
						qwer=j; 
					}
				}
			}
			peo[qwer].bie=0;
			b--; 
			if(peo[qwer].aval>=peo[qwer].cval)
			{
				peo[qwer].aie=1;
				a++;
			}
			else
			{
				peo[qwer].cie=1;
				c++;
			}
		}
		while(c>n/2)
		{
			mincha=INT_MAX;
			for(int j=0;j<n;j++)
			{
				if(peo[j].cie==1)
				{
					ma=max(peo[j].aval,peo[j].bval);
					cha[j]=peo[j].cval-ma;
					if(cha[j]<mincha)
					{
						mincha=cha[j];
						qwer=j; 
					}
				}
			}
			peo[qwer].cie=0;
			c--; 
			if(peo[qwer].aval>=peo[qwer].bval)
			{
				peo[qwer].aie=1;
				a++;
			}
			else
			{
				peo[qwer].bie=1;
				b++;
			}
		}
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(peo[j].aie==1)
			{
				ans+=peo[j].aval;
			}
			if(peo[j].bie==1)
			{
				ans+=peo[j].bval;
			}
			if(peo[j].cie==1)
			{
				ans+=peo[j].cval;
			}
		}
		answer[i]=ans;
	}
	for(int i=0;i<t;i++)
	{
		cout<<answer[i]<<endl;
	}
	return 0;
}
