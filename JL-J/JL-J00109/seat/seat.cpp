#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[20][20];
long long b[10050];
bool cmp(int i,int j){
    return i>j;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++){
        cin>>b[i];
    }

    long long r=b[1];
    sort(b+1,b+x+1,cmp);
    long long c=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2==1&&j<=m){
                a[i][j]=b[c];
            }
            else if(i%2==0&&j>=1){
                a[i][m-j+1]=b[c];
            }
            c++;

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==r) cout<<i<<" "<<j;
        }
    }
    return 0;
}
