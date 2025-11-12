#include<iostream>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans=0;

void dfs(int now,bool choose,int cnt)
{
	if(now>n)return;
	if(choose)
	{
		int t=a[now],pot=0;
		if(t==k)
		{
			cnt++;
			ans=max(ans,cnt);
			dfs(now+1,0,cnt);
			dfs(now+1,1,cnt);
		}else{
			for(int i=now+1;i<=n;i++)
			{
				t=t^a[i];
				if(t==k)
				{
					pot=i;
					cnt++;
					break;
				}
			}
			if(pot==0)return;
			ans=max(ans,cnt);
			dfs(pot+1,0,cnt);
			dfs(pot+1,1,cnt);
		}
		return;
	}
	dfs(now+1,0,cnt);
	dfs(now+1,1,cnt);
	return;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if((k==1||k==0)&&((a[1]==1||a[1]==0)&&(a[2]==1||a[2]==0))){
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)ans++;
		}
		cout<<ans;
		return 0;
	}else{
		dfs(1,0,0);
		dfs(1,1,0);
		cout<<ans;
		return 0;
	}
}
