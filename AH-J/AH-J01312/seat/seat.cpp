#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,scores[100005],score,index=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>scores[i];
    score = scores[0];
    sort(scores,scores+m*n,greater<int>());
    for(int i=0;i<m;i++){//lie
        for(int j=0;j<n;j++){
            if(scores[index] == score){
                cout<<i+1<<' '<<j+1;
                return 0;
            }
            index++;
        }
        i++;
        for(int j=n-1;j>=0;j--){
            if(scores[index] == score){
                cout<<i+1<<' '<<j+1;
                return 0;
            }
            index++;
        }
    }

    return 0;
}
