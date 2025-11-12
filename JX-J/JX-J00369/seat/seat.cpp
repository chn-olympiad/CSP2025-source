#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],a[15][15],sum,cnt,st;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>s[i];
    }
    st=s[1];
    sort(s+1,s+1+sum,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2!=0){
                a[i][j]=s[++cnt];
            }
            if(i%2==0){
                a[i][n+1-j]=s[++cnt];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==st){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
