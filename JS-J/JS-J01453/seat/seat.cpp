#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,me,score[110];
    cin>>n>>m>>me;
    score[1]=me;
    for(int i=2;i<=n*m;i++){
        cin>>score[i];
    }
    sort(score+1,score+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(score[i]==me){
            cout<<(i-1)/n+1<<" ";
            if(i%(2*n)<=n){
                cout<<i%(2*n);
            }else{
                cout<<2*n-(i%(2*n))+1;
            }
            return 0;
        }
    }
}
