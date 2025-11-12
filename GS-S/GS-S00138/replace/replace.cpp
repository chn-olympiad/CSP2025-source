#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s1,s2;
}a[100005];
int sum=0;
int t;
void so(string x,string y,int l,int e,int p)
{
	for(int i=e;i<l;i++)
	{
		if(x[i]!=y[i])
		{
			for(int j=0;j<i;j++)
			{
				for(int k=i;k<l;k++)
				{
					string c="";
					for(int w=j;w<=k;w++)
						c+=x[w];
					bool d=0;
					for(int w=p;w<=t;w++)
					{
						if(c==a[w].s1&&a[w].s2[i-j]==y[i])
						{
							string v=x;
							for(int f=j;f<=k;f++)
								v[f]=a[w].s2[f-j];
							d=1;
							so(v,y,l,i+1,1);
							so(x,y,l,i,w+1);
						}
					}
					if(d==0)
					{
						return ;
					} 
				}
			}
		}
	}
	sum++;
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string l1,l2;
		cin>>l1>>l2;
		bool f=0;
		for(int j=1;j<i;j++)
		{
			if(a[j].s2==l1)
			{
				a[j].s2=l2;
				f=1;
				break;
			}
		} 
		if(f==0)
		{
			t++;
			a[t].s1=l1;
			a[t].s2=l2;
		}
	}	
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int l=x.length();
		so(x,y,l,0,1);
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
