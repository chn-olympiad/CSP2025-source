#include<bits/stdc++.h>
using namespace std;
struct bumen{
    int ren;
    int bm1;
    int bm2;
    int bm3;
};
int main(){
    freopen("club.in","r",stdin);
    int t;
    cin>>t;
   bumen n[t][110000];
    int cishu=1;
    for(int i = 1; i <= t; i++){
        cin>>n[i][cishu].ren;
        for(int j=1;j<=n[i][j].ren;j++){
            cin>>n[i][j].bm1>>n[i][j].bm2>>n[i][j].bm3;
        }
        cishu++;
    }
    for(int i = 1; i <= t; i++){
       for(int j=1;j<=n[i][j].ren;j++){
            if(n[i][j]>n[i-1][j+1])
            {

                cout<<n[i][j]>n
            }
        }
    }
    return 0;
    freopen("club.out","w",stdout);
}
