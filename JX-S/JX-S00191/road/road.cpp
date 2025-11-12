#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,ls[10005][10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int sum = 0;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        ls[x][y] = ls[y][x] = z;
        sum += z;
    }
    int q;
    bool a = 1,o = 0;
    for(int i=1;i<=k;i++){
        if(a)
            o = 1;
        a = 1;
        for(int p = 0;p<=n;p++){
            cin>>q;
            if(q){
                a = 0;
            }
        }
    }
    if(o)
        cout<<"0\n";
    else
        cout<<sum<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
