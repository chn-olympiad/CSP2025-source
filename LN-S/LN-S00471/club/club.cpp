#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int ans;
const int N=100000;
int a[10][N+5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p;
    int n;
    cin>>p;
    for(int i=1;i<=p;i++){
            cin>>n;
        for(int j=1;j<=3*n;j++){
                cin>>a[i][j];
                if(i%3==0){
                    x=max(a[i][j],a[i][j-1]);
                    y=max(a[i][j],a[i][j-2]);
                    z=max(x,y);
                }
                ans+=z;
        }
        cout<<ans;
    }
    return 0;
}
