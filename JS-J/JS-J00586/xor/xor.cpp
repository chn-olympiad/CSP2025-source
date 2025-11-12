#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],edges[1010][1010],dist[1010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int t=1;t<=n;t++){
        int ans=0;
        for(int i=1;i<=n;i++){
            int j=i+t-1; //get end
            if(i==1){
                for(int w=1;w<=j;w++)
                    ans=ans^a[w];
                if(ans==k)
                    edges[i][j+1]=1;
                continue;
            }
            if(j>n) //end over
                continue;//go on
            ans=ans^a[i-1]^a[j];
            if(ans==k)
                edges[i][j+1]=1;
        }
    }
    for(int i=1;i<=n;i++){//dfs
        for(int j=i+1;j<=n+1;j++){
            int x=dist[i];
            if(edges[i][j]==1)
                x++;
            if(x>dist[j])
                dist[j]=x;
        }
    }
    cout<<dist[n+1]<<'\n';
    return 0;
}
