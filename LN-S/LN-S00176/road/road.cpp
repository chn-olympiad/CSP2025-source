#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[123][148],u[100],v[100],w[100];
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>a[j][i];
        }
    }
    return 0;
}
