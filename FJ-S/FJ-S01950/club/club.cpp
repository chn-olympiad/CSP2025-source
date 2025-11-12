#include <bits/stdc++.h>
using namespace std;

struct Number
{
	int a,b,c;
}num[100005];
int n;

long long dfs(int k,long long ans,int one,int two,int three)
{
	if(k==n+1) {
		return ans;
	}
	long long ans1=0,ans2=0,ans3=0;
	
	if(num[k].a>=num[k].b||num[k].a>=num[k].c)
		if(one<n/2) ans1=dfs(k+1,ans+num[k].a,one+1,two,three);
	if(num[k].b>=num[k].a||num[k].b>=num[k].c)
		if(two<n/2) ans2=dfs(k+1,ans+num[k].b,one,two+1,three);
	if(num[k].c>=num[k].a||num[k].c>=num[k].b)
		if(three<n/2) ans3=dfs(k+1,ans+num[k].c,one,two,three+1);
	return max(max(ans1,ans2),ans3);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>num[i].a>>num[i].b>>num[i].c;
		}
		cout<<dfs(1,0,0,0,0)<<"\n";
	}
	return 0;
} 
