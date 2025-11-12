#include<bits/stdc++.h>
using namespace std;
vector<int> c;
int seat[11][11];
bool cmd(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int t;
        cin>>t;
        c.push_back(t);
    }
    int rc=c[0],idx=0;
    sort(c.begin(),c.end(),cmd);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(c[idx]==rc){
                    cout<<i<<' '<<j;
                    return 0;
                }
                idx++;
            }
        }
        else{
            for(int j=n;j>0;j--){
                if(c[idx]==rc){
                    cout<<i<<' '<<j;
                    return 0;
                }
                idx++;
            }
        }
    }
    return 0;
}
