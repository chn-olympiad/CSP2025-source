#include<bits/stdc++.h>
using namespace std;
int n,m;
long long score[5005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>score[i];
    }
    long long p=score[0];
    sort(score,score+n*m,cmp);
    int now=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(score[now++]==p){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }

        }else{
            for(int j=n;j>=1;j--){
                if(score[now++]==p){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }

        }
    }


    return 0;
}

