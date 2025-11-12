#include<bits/stdc++.h>
using namespace std;
int T,n,ans,b[3];
int a[3][100005];
void dfs(int k,int sum)
{
    if(k==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(b[i]==n/2) continue;
        b[i]++;
        dfs(k+1,sum+a[i][k]);
        b[i]--;
    }
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
    {
        ans=0;
        bool flag1=1;//teshuxingzhiAB
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[0][i]>>a[1][i]>>a[2][i];
            if(a[1][i]!=0||a[2][i]!=0) flag1=0;
            //if(a[i][2]!=0) flag2=0;
        }
        if(flag1==1)
        {
            sort(a[0]+1,a[0]+n+1);
            for(int i=n;i>n/2;i--)
                ans+=a[0][i];
            cout<<ans<<'\n';
        }
        else
        {
            dfs(1,0);
            cout<<ans<<'\n';
        }
    }
	return 0;
}
