#include<bits/stdc++.h>
#define N 100010
using namespace std;
struct node
{
	int happiness,id,need;
	bool operator<(const node &k)const
	{
		return happiness>k.happiness;
	}
}t[N];
int _,n,ans;
int qwq[10],ppl[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--)
	{
		ans=ppl[1]=ppl[2]=ppl[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			qwq[1]=a;
			qwq[2]=b;
			qwq[3]=c;
			sort(qwq+1,qwq+4);
			a-=qwq[2];
			b-=qwq[2];
			c-=qwq[2];
			ans+=qwq[2];
			if(a==qwq[3]-qwq[2])
				t[i]={qwq[3]-qwq[2],i,1};
			if(b==qwq[3]-qwq[2])
				t[i]={qwq[3]-qwq[2],i,2};
			if(c==qwq[3]-qwq[2])
				t[i]={qwq[3]-qwq[2],i,3};
		}
		sort(t+1,t+n+1);
		for(int i=1;i<=n;i++)
			if(ppl[t[i].need]!=(n>>1))
			{
				ppl[t[i].need]++;
				ans+=t[i].happiness;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
