#include<iostream>
#include<algorithm>
using namespace std;
int T;
int n,a[100005][4],ans=-1,vis[4];
bool check1()
{
	for(int i=1;i<=3;i++) if(vis[i]>n/2) return 0;
	return 1;
}
void dfs(int k,int sum)
{
	if(!check1()) return;
	else if(k>n)
	{
		ans=max(ans,sum);
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			vis[i]++;
			dfs(k+1,sum+a[k][i]);
			vis[i]--;
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
	    ans=-1;
	    bool subtask1=0,subtask2=1,subtask3=0;
		cin>>n;
		if(n<=200) subtask1==1;
		for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
            if(a[i][2]!=0&&a[i][3]!=0) subtask2==0;
            else if(a[i][3]!=0) subtask3=0;
        }
		if(subtask1)
        {
            dfs(1,0);
            cout<<ans;
        }
        else if(subtask2)
        {
            ans=0;
            int temp[100005];
            for(int i=1;i<=n;i++)
            {
                temp[i]=a[i][1];
            }
            sort(temp+1,temp+n+1,greater<int>());
            for(int i=1;i<=n/2;i++) ans+=temp[i];
            cout<<ans;
        }

	}
    return 0;
}
