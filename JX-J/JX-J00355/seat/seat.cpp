#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N][N];
vector<int>b(N*N);
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,fs;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(i==1){
            fs=b[i];
        }
    }
    sort(b.begin(),b.end(),cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2==0){
                a[i][j]=b[(i-1)*m+n-j+1];
            }else{
                a[i][j]=b[(i-1)*m+j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==fs){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
