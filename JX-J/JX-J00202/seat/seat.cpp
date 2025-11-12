#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int s[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int q=n*m;
    int ai;
    cin>>ai;
    for(int i=1;i<q;i++){
        cin>>s[i];
    }
    sort(s+1,s+q-1,cmp);
    int c=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[c]<ai){
                cout<<i<<' '<<j;
                return 0;
            }
            else a[i][j]=s[c];
            c++;
        }
    }
    return 0;
}
