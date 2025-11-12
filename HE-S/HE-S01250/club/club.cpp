#include<bits/stdc++.h>
using namespace std;
int t,x,sum,d1,d2,d3;
int ans[100001][3],biao[3],ren[100001],best[10001],z1[100001],z2[100001],z3[100001];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>x;
        sum = 0;
        int ou = x/2;
        for(int i = 0;i<x;i++){
            for(int j = 0;j<3;j++){
                cin>>ans[j][i];
            }
        }
        for(int i = 0;i<x;i++){
            for(int j = 0;j<3;j++){
                best[i] = max(ans[j][i],ans[j+1][i]);
            }
        }
        for(int i = 0;i<x;i++){
            sum+=best[i];
        }
        cout<<sum<<endl;
    }
}
