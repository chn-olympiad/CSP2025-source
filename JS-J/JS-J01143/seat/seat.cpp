#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    int n,m;
    cin>>n>>m;
    int seat_total[n][m];
    int score_total[n*m+2];
    for(int i=0;i<n*m;i++){
        cin>>score_total[i];

    }
    int score_R=score_total[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<i;j++){
            if(score_total[i]>score_total[j]){
                swap(score_total[i],score_total[j]);
            }
        }
    }

    //for(int i=0;i<n*m;i++){
        //cout<<score_total[i];
    //}
    int number_R;
    for(int i=0;i<n*m;i++){
        if(score_R==score_total[i]){
            number_R=i;
            break;
        }

    }
    //cout<<number_R;
    int a=0;
    for(int i=0;i<m;i++){
        if(m%2!=0){
            for(int j=0;j<n;j++){
                seat_total[i][j]=a;
                a+=1;
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                seat_total[i][j]=a;
                a+=1;
            }
        }

    }
    int p;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(seat_total[i][j]+1==number_R){
                cout<<i+1<<' '<<j+1;
                p=j;
                break;
            }
        }
        if(seat_total[i][p]==number_R){
            break;
        }
    }
    //for(int i=0;i<m;i++){
       // for(int j=0;j<n;j++){
        //    cout<<seat_total[j][i]<<number_R;
      //  }
   // }
    return 0;
}
