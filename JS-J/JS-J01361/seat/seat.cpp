#include<bits/stdc++.h>
using namespace std;
struct stu{
    int sco,rank;
}score[102];
bool cmp(stu a,stu b){
    return a.sco>b.sco;
}
int m,n;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>score[i].sco;
        score[i].rank=i;
    }
    sort(score+1,score+(m*n)+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1)
            for(int j=1;j<=n;j++){
                if(score[n*(i-1)+j].rank==1){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        else
            for(int j=n;j>=1;j--){
                if(score[n*(i-1)+n-j+1].rank==1){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
    }
    cout<<-1;
    return 0;
}
