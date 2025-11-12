#include <bits/stdc++.h>
using namespace std;
int n,m,R;
int scores[105];
int seat[15][15];
bool cmp(const int& a,const int& b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>scores[i];
    }
    R=scores[1];
    sort(scores+1,scores+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){

        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                seat[i][j]=scores[cnt];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                cnt++;
                seat[i][j]=scores[cnt];
            }

        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(seat[i][j]==R){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
