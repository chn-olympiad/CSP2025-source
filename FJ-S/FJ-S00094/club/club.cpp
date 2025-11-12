#include<bits/stdc++.h>
using namespace std;
int t,n,fi,se,tr;
long long ans;
struct node{
	int a,b,c,p;
}l[100005];
bool cmp(node x,node y)
{
	if(x.a-max(x.b,x.c)<y.a-max(y.b,y.c))return true;
	else return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
    	ans=0;
    	fi=0;
    	se=0;
    	tr=0;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>l[i].a>>l[i].b>>l[i].c;
    		if(l[i].a>=l[i].b&&l[i].a>=l[i].c)
    		{
    			fi++;
    			l[i].p=1;
    			continue;
			}
			if(l[i].b>=l[i].a&&l[i].b>=l[i].c)
    		{
    			se++;
    			l[i].p=2;
    			continue;
			}
			if(l[i].c>=l[i].b&&l[i].c>=l[i].a)
    		{
    			tr++;
    			l[i].p=3;
    			continue;
			}
		}
		if(se>n/2)
		{
			swap(fi,se);
			for(int i=1;i<=n;i++)
			{
				swap(l[i].a,l[i].b);
				if(l[i].p==1)
				l[i].p=2;
				else if(l[i].p==2)
				l[i].p=1;
			}
		}
		if(tr>n/2)
		{
			swap(fi,tr);
			for(int i=1;i<=n;i++)
			{
				swap(l[i].a,l[i].c);
				if(l[i].p==1)
				l[i].p=3;
				else if(l[i].p==3)
				l[i].p=1;
			}
		}
		if(fi>n/2)
		{
			sort(l+1,l+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(fi==n/2)
				break;
				if(l[i].p==1)
				{
					if(l[i].b>l[i].c)
					{
						fi--;
					    se++;
					    l[i].p=2;
					}
					else
					{
						fi--;
					    tr++;
					    l[i].p=3;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i].p==1)
			ans+=l[i].a;
			if(l[i].p==2)
			ans+=l[i].b;
			if(l[i].p==3)
			ans+=l[i].c;
		}
		cout<<ans<<"\n";
	}
    return 0;
}
