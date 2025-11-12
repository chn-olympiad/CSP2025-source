#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
const int MAXM=105;
int a[MAXN][MAXN];
int b[MAXM];
bool cmp(int x,int y){
    return x>y;
}
int ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    ans=b[0];
    sort(b,b+k,cmp);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=b[i];
            if(a[i][j]==ans){
                cout<<i+1<<' '<<j+1;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
