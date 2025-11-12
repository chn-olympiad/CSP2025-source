#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int zhun;
    cin>>zhun;
    int cnt=1;
    int xx;
    for(int i=2;i<=n*m;i++){
        cin>>xx;
        if(xx>zhun)cnt++;
    }
    int nowi=1,nowj=1;
    cnt--;
    while(cnt){
        if(nowj%2==0){
            if(nowi==1)nowj++;
            else nowi--;
        }else{
            if(nowi==n)nowj++;
            else nowi++;
        }
        cnt--;
    }
    cout<<nowj<<" "<<nowi;
    return 0;
}
