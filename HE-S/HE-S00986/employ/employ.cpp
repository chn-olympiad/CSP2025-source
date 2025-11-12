#include<iostream>
using namespace std;
int main()
{
	cout<<"基本没学，已废，明年再战" ; 
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//草稿: 
/*

1.

		for(int i=1;i<=sum;i++)
		{
			for(int j=i;j<=sum;j++)
			{
				if(a[i].key<a[j].key)
				{
					swap(a[i],a[j])
				}
			}
		}

2.

1
5
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5

3.

		
		
		
		 
		for(int i=1;i<=n;i++)
		{
			cout<<a[i].key<<' '<<a[i].s<<endl;
		}
		cout<<"******************"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<b[i].key<<' '<<b[i].s<<endl;
		}
		cout<<"******************"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<c[i].key<<' '<<c[i].s<<endl;
		}

4.

#include<bits/stdc++.h>
using namespace std;
int maxxx,n;
int a[100005],b[100005],c[100005];
void dfs(int su,int ans,int ua,int ub,int uc)
{	
	if((ua>n/2)||(ub>n/2)||(uc>n/2))
	{
		return;
	}
	//cout<<ua<<endl;
	if(su==0)
	{
		//cout<<"***************"<<endl;
		maxxx=max(maxxx,ans);
		//cout<<maxxx<<','<<ans;
		return;
	}
	dfs(su-1,ans+=a[su],ua+1,ub,uc);
	ans-=a[su];
	dfs(su-1,ans+=b[su],ua,ub+1,uc);
	ans-=b[su];
	dfs(su-1,ans+=c[su],ua,ub,uc+1);

}
int main()
{
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,sum,ans;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int j;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		dfs(n,0,0,0,0);
		cout<<maxxx<<endl;
		maxxx=0;
	}
	return 0;
}

5.

#include<bits/stdc++.h>
using namespace std;

//int a1[100005],b1[100005],c1[100005],;
struct prople
{
	int key;
	int s;
}a[100005],b[100005],c[100005];
struct cmp
{
	int key;
	int s;
}a1[100005],b1[100005],c1[100005];
int main()
{
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sum,ans;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int j;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].key>>b[j].key>>c[j].key;
			a1[j].key=a[j].key;
			b1[j].key=b[j].key;
			c1[j].key=c[j].key;
			a1[j].s=j;
			b1[j].s=j;
			c1[j].s=j;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a1[i].key<a1[j].key)
				{
					swap(a1[i],a1[j]);
				}
				if(b1[i].key<b1[j].key)
				{
					swap(b1[i],b1[j]);
				}
				if(c[i].key<c[j].key)
				{
					swap(c1[i],c1[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[a1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			b[b1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			c[c1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].s<b[i].s)
			{
				if(a[i].s<c[i].s)
				{
					ans+=a[i].key;	
				}
				else
				{
					if(a[i].s>c[i].s)
					{
						ans+=a[i].key;
					}
					else
					{
						ans+=max(a[i].key,c[i].key);
					}
				}
			}
			else
			{
				if(b[i].s<c[i].s)
				{
					ans+=b[i].key;
				}
				else
				{
					if(b[i].s>c[i].s)
					{
						ans+=c[i].key;
					}
					else
					{
						if(a[i].s==b[i].s)
						{
							ans+=max(a[i].key,b[i].key);
						}
						else
						{
							ans+=max(b[i].key,c[i].key);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}

D.
#include<bits/stdc++.h>
using namespace std;

//int a[100005][3],b[100005],c[100005],a1[100005];
struct mapu
{
	
}a,b,c;
int main()
{
	int t,n,sum;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int j;
		for(j=1;j<=n;j++)
		{
			cin>>a[j][1]>>b[j]>>c[j];
			a[j][2]=j;
			//d[j][2]=j;
			//d[j][3]=j;
		}
		sum=j;
		for(int i=1;i<=sum;i++)
		{
			for(int j=i;j<=sum;j++)
			{
				if(a[i][1]<a[j][1])
				{
					swap(a[i],a[j]);
					a1[a[i][2]]=j;
					a1[a[j][2]]=i;
				}
			}
		}
		/*for(int i=1;i<=sum;i++)
		{
			for(int j=i;j<=sum;j++)
			{
				if(b[i]<b[j])
				{
					swap(b[i],b[j]);
					d[i][2]=j;
					d[j][2]=i;
				}
			}
		}
		for(int i=1;i<=sum;i++)
		{
			for(int j=i;j<=sum;j++)
			{
				if(c[i]<c[j])
				{
					swap(c[i],c[j]);
					d[i][3]=j;
					d[j][3]=i;
				}
			}
		}
		/*sort(a+1,a+sum+1);
		sort(b+1,b+sum+1);
		sort(c+1,c+sum+1);
		for(int i=1;i<sum;i++)
		{
			cout<<a[i][1]<<' '<<a1[i]<<endl;
		}
	}

	
	return 0;
}

B.
#include<bits/stdc++.h>
using namespace std;

//int a1[100005],b1[100005],c1[100005],;
struct prople
{
	int key;
	int s;
}a[100005],b[100005],c[100005];
struct cmp
{
	int key;
	int s;
}a1[100005],b1[100005],c1[100005];
int main()
{
	freopen("club1.in","r",stdin);
	freopen("clun.out","w",stdout);
	int t,n,sum,ans;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int j;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].key>>b[j].key>>c[j].key;
			a1[j].key=a[j].key;
			b1[j].key=b[j].key;
			c1[j].key=c[j].key;
			a1[j].s=j;
			b1[j].s=j;
			c1[j].s=j;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a1[i].key<a1[j].key)
				{
					swap(a1[i],a1[j]);
				}
				if(b1[i].key<b1[j].key)
				{
					swap(b1[i],b1[j]);
				}
				if(c[i].key<c[j].key)
				{
					swap(c1[i],c1[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[a1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			b[b1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			c[c1[i].s].s=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].s<b[i].s)
			{
				if(a[i].s<c[i].s)
				{
					ans+=a[i].key;	
				}
				else
				{
					if(a[i].s>c[i].s)
					{
						ans+=a[i].key;
					}
					else
					{
						ans+=max(a[i].key,c[i].key);
					}
				}
			}
			else
			{
				if(b[i].s<c[i].s)
				{
					ans+=b[i].key;
				}
				else
				{
					if(b[i].s>c[i].s)
					{
						ans+=c[i].key;
					}
					else
					{
						if(a[i].s==b[i].s)
						{
							ans+=max(a[i].key,b[i].key);
						}
						else
						{
							ans+=max(b[i].key,c[i].key);
						}
					}
				}
			}
		}
		cout<<ans;
	}
	
	
	return 0;
}

A.#include<bits/stdc++.h>
using namespace std;

//int a[100005][3],b[100005],c[100005],a1[100005];
struct mapu
{
	int key;
	int id;
	
}a[100005],b[100005],c[100005];
int main()
{
	int t,n,sum;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int j;
		for(j=1;j<=n;j++)
		{
			cin>>a[j].key>>b[j].key>>c[j].key;
			a[j].id=b[j].id=c[j].id=j;
		}
		int sum=j;
		for(int i=1;i<=sum;i++)
		{
			for(int j=i;j<=sum;j++)
			{
				if(a[i].key<a[j].key)
				{
					swap(a[i],a[j]);
				}
				if(b[i].key<b[j].key)
				{
					swap(b[i],b[j]);
				}
				if(c[i].key<c[j].key)
				{
					swap(c[i],c[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<a[i].key<<' '<<a[i].id<<endl;
		}
	}
	
	
	return 0;
}



*/
