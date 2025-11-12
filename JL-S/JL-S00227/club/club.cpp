#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int sr[21000]={0};
    int t;
    cin>>t;
    int n[t+10]={0},ans[t+10]={0};
    for(int i=1;i<=t;i++)
    {
		cin>>n[i];
		int a1[n[i]+10]={0};
		int a2[n[i]+10]={0};
		int a3[n[i]+10]={0};
		for(int j=1;j<=n[i];j++)
			cin>>a1[j]>>a2[j]>>a3[j];
		if(n[i]==2)
		{
		    ans[i]=max(a1[1]+a2[2],a1[1]+a3[2]);
		    ans[i]=max(ans[i],a2[1]+a1[2]);
		    ans[i]=max(ans[i],a2[1]+a3[2]);
		    ans[i]=max(ans[i],a3[1]+a1[2]);
		    ans[i]=max(ans[i],a3[1]+a2[2]);
		    cout<<ans[i]<<endl;
		    continue;
		}
		else
		{
			int r=n[i]/2;
			for(int o1=1;o1<=n[i];o1++)
	            sr[a1[o1]]++;
	        for(int o2=20500;o2>=1;o2--)
	        {
				if(sr[o2]!=0)
				{
					for(int o3=sr[o2];o3>=1;o3--)
					{
						ans[i]+=o2;
						r--;
						if(r<=0) break;
					}
				}
				if(r<=0)
				{
					cout<<ans[i]<<endl;
					break;
				}
			}
		}
	}
    return 0;
}
