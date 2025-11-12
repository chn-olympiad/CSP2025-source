#include <bits/stdc++.h>
using namespace std;
int g[110];
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>g[i];
        if(i==1){
            k=g[i];
        }
    }
    sort(g+1,g+n*m+1,greater<int>());
    int j=1,z=1,x=1,y=1;
    if(n==1){
        while(g[j]!=k){
            x++;
            j++;
        }
        cout<<x<<" "<<y;
        return 0;
    }
    bool ud=1,fr=0;
    while(g[j]!=k){
        if(x==1&&y==1){
            y++;
            j++;
            continue;
        }
        if((y==n||y==1)&&fr==0){
            fr=1;
            x++;
        }else if((y==n||y==1)&&fr==1){
            ud=!ud;
            z=(int(ud)*2-1);
            y+=z;
            fr=0;
        }else{
            y+=z;
        }
        j++;
    }
    cout<<x<<" "<<y;
    return 0;
}
