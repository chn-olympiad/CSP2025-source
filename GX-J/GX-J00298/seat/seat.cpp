#include<bits/stdc++.h>
using namespace std;
bool cmp (int a,int b){
    return a>b;
}
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[10][10];
    int R;
    int n,m;
    cin >> n >> m;
    int que[n*m+1];
    for(int i=0;i<n*m;i++){
        cin >> que[i];
    }
    R=que[0];
    sort(que,que+n*m,cmp);

    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(n%2==0){//oushu
                a[i][m-j-1]=que[sum];
                sum++;
                if(a[i][m-j-1]==R){
                    cout  << i+1 << ' ' <<j+1;
                    continue ;
                }
            }
            else{
                a[i][j]=que[sum];
                sum++;
                if(a[i][j]==R){
                    cout  << i+1 << ' ' <<j+1;
                    continue ;
                }
            }
    }
    }

    return 0;
}
