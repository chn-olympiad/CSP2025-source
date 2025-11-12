#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main()
{
	cin.tie(0);
	cout.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T;
    cin>>T;
    while(T--)
    {
        int n,suma=0,sumb=0,sumc=0;
        cin>>n;
        vector<int> adj[3],anv[3];
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            anv[0].push_back(a);
            anv[1].push_back(b);
            anv[2].push_back(c);
        }

        for(int i=0;i<n;i++)
        {
            if(anv[0][i]>=anv[1][i] and anv[0][i]>=anv[2][i]){
                adj[0].push_back(i);
                suma+=anv[0][i];
            }
            else if(anv[1][i]>=anv[0][i] and anv[1][i]>=anv[2][i]){
                adj[1].push_back(i);
                sumb+=anv[1][i];
            }
            else{
                adj[2].push_back(i);
                sumc+=anv[2][i];
            }
        }

        if(adj[0].size()<=n/2 and adj[1].size()<=n/2 and adj[2].size()<=n/2) cout<<suma+sumb+sumc<<endl;
        else{
            int p;
            if(adj[0].size()>n/2) p=0;
            else if(adj[1].size()>n/2) p=1;
            else p=2;

            int s=adj[p].size()-n/2,sum=suma+sumb+sumc;
            vector<int> a;

            for(int i=0;i<adj[p].size();i++)
            {
                int ccf=1E18;
                for(int j=0;j<3;j++)
                {
                    if(j==p) continue;
                    ccf=min(anv[p][adj[p][i]]-anv[j][adj[p][i]],ccf);
                }
                a.push_back(ccf);
            }
            sort(a.begin(),a.end());

            for(int i=0;i<s;i++) sum=sum-a[i];

            cout<<sum<<endl;
        }
    }
	return 0;
}
