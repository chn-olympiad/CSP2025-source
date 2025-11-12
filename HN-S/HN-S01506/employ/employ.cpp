#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
const int m=998244353;
string dif;
bool flag[100];
int pai[100],n,k,fact[100];

int dfs(int i,int cnt1,int cnt2)
{
	int ans=0;
	if(i>n)return (cnt1>=k);
	
	for(int j=1;j<=n;j++)
	{
		if(flag[j])continue;
		flag[j]=1;
		if(pai[j]<cnt2||dif[i]==1)ans+=dfs(i+1,cnt1,cnt2+1);
		else ans+=dfs(i+1,cnt1+1,cnt2);
		flag[j]=0;
		ans%=m;
	}
	return ans%m;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	cin>>dif;
	dif=' '+dif;
	fact[0]=1;
	for(int i=1;i<=n;i++)cin>>pai[i],fact[i]=i*fact[i-1];
	cout<<dfs(1,0,0);
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
	

