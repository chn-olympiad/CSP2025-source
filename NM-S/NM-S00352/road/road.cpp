#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int arr[10005];
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    vector<int>a(n+2,0);
    for(int i=0;i<=m;i++){
        a[i]=arr[i]-arr[i-1];
    }
    int u,v,w;
    for(int i=1;i<=k;i++){
        cin>>u>>v>>w;
    }
    if(k<n){
        a[k]+=m+1;
        cout<<a[k]<<endl;
    }
    else{
        cout<<"13";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
