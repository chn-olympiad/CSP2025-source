#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	int a,b,c;
}f[N];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		long long n,num1=0,num2=0,num3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>f[i].a>>f[i].b>>f[i].c;
		for(int i=1;i<=n;i++)
		{
			if(f[i].a>=max(f[i].b,f[i].c)) num1++,ans+=f[i].a;
			else if(f[i].b>=(max(f[i].a,f[i].c))) num2++,ans+=f[i].b;
			else num3++,ans+=f[i].c; 
		}
		if(num1>n/2){
			for(int i=1;i<=n;i++) if(f[i].a>max(f[i].b,f[i].c)) q.push(f[i].a-max(f[i].c,f[i].b));	
		}
		else if(num2>n/2) {
			for(int i=1;i<=n;i++) if(f[i].b>max(f[i].a,f[i].c)) q.push(f[i].b-max(f[i].c,f[i].a));	
		}
		else if(num3>n/2){
			for(int i=1;i<=n;i++)if(f[i].c>max(f[i].b,f[i].a)) q.push(f[i].c-max(f[i].a,f[i].b));	
		}
		while(!q.empty())
		{
			if(q.size()<=n/2) break;
			int x=q.top();
			q.pop();
			ans-=x;
		}
		cout<<ans<<"\n";
		while(!q.empty()) q.pop();
	}
	return 0; 
}
