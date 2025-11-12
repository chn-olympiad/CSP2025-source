#include<bits/stdc++.h>
using namespace std;
string a,b;
#define int long long
int n,q;
struct ed
{
	string l,r;
	int fr,lt;
}pd[100005];
int head,endp;
void clear()
{
	return;
}

signed find1(string a,string b)
{
	int qq=-1;
	int flag=0;
	int gp=a.size();
	while(flag==0&&qq<gp)
	{
		qq+=1;
		if(a[qq]!=b[qq])
		{
			flag=1;
		}
	}
	return qq;
}
signed find2(string a,string b)
{
	int qq=a.size();
	int flag=0;
	while(flag==0&&qq>-1)
	{
		qq-=1;
		if(a[qq]!=b[qq])
		{
			flag=1;
		}
	}
	return qq;
}
signed check(int x)
{
	if((pd[x].lt-pd[x].fr)!=(endp-head))
	{
		
		return 0;
	}
	int ldd=pd[x].fr;
	int pa=pd[x].l.size();
	for(int i=0;i<pa;i++)
	{
		if(pd[x].l[i]!=a[head-ldd+i]||pd[x].r[i]!=b[head-ldd+i])
			return 0;
	}
	return 1;
	
}
void solve1()
{
	clear();
	for(int i=1;i<=n;i++)
	{
		cin>>pd[i].l>>pd[i].r;
		pd[i].fr=find1(pd[i].l,pd[i].r);
		pd[i].lt=find2(pd[i].l,pd[i].r);
		//cout<<pd[i].fr<<" "<<pd[i].lt<<endl;
		
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		head=find1(a,b);
		endp=find2(a,b);

		//cout<<head<<" "<<endp<<endl;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			
			if(check(i)==1)
			{
				//cout<<i<<endl;
				ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	solve1();
	return 0;
}
