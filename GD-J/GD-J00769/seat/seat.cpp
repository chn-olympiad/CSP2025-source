#include<bits/stdc++.h>
using namespace std;
#ifndef zhouyi
#define dbg
#define breakpoint
#else
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define breakpoint getchar()
#endif
int cs[10][10];
int main(){
    #ifndef zhouyi
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    short ahead=1;
    vector<int> ss(n*m);
    int a1;
    for(int i=0;i<n*m;++i){
        cin>>ss[i];
    }
    a1=ss[0];
    sort(ss.begin(),ss.end(),[](int a,int b){
        return a>b;
    });
    int index=0;
    for(int i=0;i<n;++i){
        if(ahead>0){
            for(int j=0;j<m;++j){
                if(ss[index++]==a1){
                    cout<<i+1<<' '<<j+1;
                    return 0;
                }
            }
            ahead*=-1;
        }else{
            for(int j=m-1;j>=0;--j){
                if(ss[index++]==a1){
                    cout<<i+1<<' '<<j+1;
                    return 0;
                }
            }
            ahead*=-1;
        }
    }
    
    return 0;
}