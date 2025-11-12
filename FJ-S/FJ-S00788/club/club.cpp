#include<bits/stdc++.h>
using namespace std;
int T;
int n,maxn = 0,top;
struct CLUBE
{
	int a,b,c;
};
CLUBE clube[100005];
void dfs(int p,int sum,int acnt,int bcnt,int ccnt)
{
	//cout<< p<<" "<<sum<<" "<< maxn<<endl;
	//cout<<acnt<<" "<<bcnt<<" "<<ccnt<<endl;
	if(p>n)
	{
		maxn = max(maxn,sum);
		return ;
	}
	if(acnt<top) 
	{
		//cout<<"a->";
		dfs(p+1,sum+clube[p+1].a,acnt+1,bcnt,ccnt);
	}
	if(bcnt<top) 
	{
		//cout<<"b->";
		dfs(p+1,sum+clube[p+1].b,acnt,bcnt+1,ccnt);
	}
	if(ccnt<top) 
	{
		//cout<<"c->";
		dfs(p+1,sum+clube[p+1].c,acnt,bcnt,ccnt+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	for(int t = 1;t<=T;t++)
	{
		cin >> n;
		maxn = 0,top = n/2;
		for(int i = 1;i<=n;i++)	cin>> clube[i].a>> clube[i].b>> clube[i].c;
		dfs(0,0,0,0,0);
		cout<< maxn;
	}
	return 0;
}
