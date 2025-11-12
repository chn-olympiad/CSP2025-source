#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5001];
int cnt;
void dfs(int x,int sum,int num,int g,int t){
	if(x==n+2){
		return;
	}
	if(g>=3&&sum!=t){
		if(sum>num*2) 
		{
			cnt++;
			cnt%=998244353;
		}
	}
	dfs(x+1,sum+a[x],max(num,a[x]),g+1,sum);
	dfs(x+1,sum,num,g,sum);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	int g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) g++;
	}
	if(g==0){
		int c=1,d=2;
		for(int i=3;i<=n;i++){
			cnt+=c*c;
			int p=d;
			d=c+d;
			c=p;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
