#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int n,m,k,i=1,j=1;
int a[N][N],score[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>score[i];
    k=score[1];

    sort(score+1,score+n*m+1);
    int sum=n*m;

    for(int j=1;j<=m;j++){
        if(i){
           for(i=1;i<=n;i++){
                a[i][j]=score[sum];
                sum--;
            }
        }else{
            for(i=n;i>=1;i--){
                a[i][j]=score[sum];
                sum--;
            }
        }

        if(j%2)
            i=n;
        else
            i=1;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==k){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
