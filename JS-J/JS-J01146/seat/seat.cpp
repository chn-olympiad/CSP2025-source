#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int score[100],n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++) cin>>score[i];
    int r_score=score[0];
    sort(score,score+n*m,cmp);
    bool flag=true;
    int sum=0;
    for(int i=1;i<=m;i++){
        if(flag){
            for(int j=1;j<=n;j++){
                if(score[sum]==r_score){
                    cout<<i<<" "<<j;
                    return 0;
                }
                sum++;
            }
            flag=false;
        }else{
            for(int j=n;j>=1;j--){
                if(score[sum]==r_score){
                    cout<<i<<" "<<j;
                    return 0;
                }
                sum++;
            }
            flag=true;
        }
    }
    return 0;
}
