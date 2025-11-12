#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
#define ll long long
#define endl "\n"
using namespace std;
struct node
{
	int a,b,c,sum;
	char h;
}a[100005];
int main()
{
//  不要注释freopen
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	我要上迷惑行为大赏 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	for(int o=1;o<=t;o++)
	{
		int n;cin>>n;ll ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b && a[i].a>=a[i].c)a[i].h='a',a[i].sum=a[i].a-max(a[i].b,a[i].c);
			if(a[i].b>=a[i].a && a[i].b>=a[i].c)a[i].h='b',a[i].sum=a[i].b-max(a[i].a,a[i].c);
			if(a[i].c>=a[i].a && a[i].c>=a[i].b)a[i].h='c',a[i].sum=a[i].c-max(a[i].a,a[i].b);
		}
		priority_queue<pair<int,int> >q;
		//first贡献度,second下标 
		for(int i=1;i<=n;i++)q.push({a[i].sum,i});
		int suma=0,sumb=0,sumc=0;
		while(!q.empty())
		{
			int i=q.top().second;
			q.pop();
			if(a[i].h=='a')
			{
				if(suma<n/2)suma++,ans+=a[i].a;
				else if(sumb<n/2 && sumc<n/2)a[i].h=(a[i].b>=a[i].c?'b':'c'),q.push({abs(a[i].b-a[i].c),i});
				else if(sumb<n/2)sumb++,ans+=a[i].b;
				else if(sumc<n/2)sumc++,ans+=a[i].c;
			}
			else if(a[i].h=='b')
			{
				if(sumb<n/2)sumb++,ans+=a[i].b;
				else if(suma<n/2 && sumc<n/2)a[i].h=(a[i].a>=a[i].c?'a':'c'),q.push({abs(a[i].a-a[i].c),i});
				else if(suma<n/2)suma++,ans+=a[i].a;
				else if(sumc<n/2)sumc++,ans+=a[i].c;
			}
			else if(a[i].h=='c')
			{
				if(sumc<n/2)sumc++,ans+=a[i].c;
				else if(suma<n/2 && sumb<n/2)a[i].h=(a[i].a>=a[i].b?'a':'b'),q.push({abs(a[i].a-a[i].b),i});
				else if(suma<n/2)suma++,ans+=a[i].a;
				else if(sumb<n/2)sumb++,ans+=a[i].b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
