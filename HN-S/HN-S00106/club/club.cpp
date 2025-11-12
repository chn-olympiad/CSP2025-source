#include<bits/stdc++.h>
using namespace std;
int t,n,a[205][5],b[5],v,vm;
void dfs(int x)
{
	if(x>n) return;
	for(int i=1;i<=3;i++) 
	{
		if(b[i]+1>n/2) continue;
		v+=a[x][i];
		b[i]++;
		dfs(x+1);
		vm=max(vm,v);
		v-=a[x][i];
		b[i]--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
		dfs(1);
		cout<<vm<<endl;
		vm=0;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
