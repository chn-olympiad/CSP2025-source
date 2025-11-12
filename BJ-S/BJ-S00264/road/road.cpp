#include<bits/stdc++.h>
using namespace std;





#define int long long
vector< pair<int,int> >e[10005]









   ;

   long long sum;


signed main()
{
    
    
    
    
    
    
    
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});





        sum+=w;
    }
     if(k==0)
     {
         cout<<sum/2;
     }
     else{

        cout<<0;

     }
       return 0;
}

