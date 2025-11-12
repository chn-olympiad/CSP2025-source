#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[100][100];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0];
    sort(a,a+n*m,cmp);
    int t=0,i;
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j++){
            b[j][i]=a[t];
            t++;
        }
        for(int j=m-1;j>=0;j--){
            b[j][i+1]=a[t];
            t++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==s){
                cout<<j+1<<" "<<i+1;
            }
        }
    }
    return 0;
}
