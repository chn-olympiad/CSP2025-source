#include<bits/stdc++.h>
using namespace std;

// <<Baldi's Basics Plus>> Now Sell On 25% Off!

int n;
vector<int> w;
int cnt=0;
int big;
int jg;
int h=1;
void dfs(int a,int n,int all){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cnt++;
   // cout << w[a]<<endl;
    if(cnt>n){
        if(all>big*2){
            jg++;
            big=0;
            cnt=0;
            h=1;
            return;
        }else{
            //NULL
            return;
        }
    }else{
        if(w[a]>big){
            big=w[a];
        }
        all+=w[a];
        //cout << w[a];
        while(h<=n){
            if(h!=a){
                 dfs(h,n,all);
            }
            h++;
            //cout <<' ';
        }
        return;
    }
    return;
}
int main(){
    int xxx;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> xxx;
        w.push_back(xxx);
    }
    for(int i=3;i<=n;i++){
        for(int ii=0;ii<=n-1;ii++){
            dfs(ii,i,0);
        }
    }
    cout << jg;
    return 0;
}
// I hope you like bees!
// Because it's time for spelling!
// Furry fans!
// *slap*
// *BUZZ*
/* _____________
   | Yuanshen  |
   |BUS STATION|
   _____________    */
