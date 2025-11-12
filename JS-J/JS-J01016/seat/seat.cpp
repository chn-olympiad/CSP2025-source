#include<bits/stdc++.h>
using namespace std;

const int N=105;
int pos[15][15];
int arr[N];

bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1; i<=n*m; i++) cin>>arr[i];
    int f=arr[1],cf=0,rf=0;
    sort(arr+1, arr+1+sum, cmp);
    for(int i=1; i<=n; i++){
        if(i%2!=0){
            for(int j=1; j<=m; j++){
                pos[i][j]=arr[i*m-m+j];
            }
        }
        if(i%2==0){
            for(int j=1; j<=m; j++){
                pos[i][j]=arr[i*m-j+1];
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(pos[i][j]==f){
                cf=i;
                rf=j;
                break;
            }
        }
    }
    cout<<cf<<" "<<rf;
    return 0;
}
