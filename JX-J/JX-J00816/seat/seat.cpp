#include<bits/stdc++.h>
using namespace std;
int n,m,b[110][110],x;
struct node{
    int a;
}s[110];
bool cmp(node xx,node yy){
    return xx.a>yy.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i].a;
    }
    x=s[1].a;
    sort(s+1,s+1+n*m,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=s[(j-1)*m+i].a;
            }
        }else{
            for(int i=n;i>=1;i--){
                b[i][j]=s[(j-1)*m+(n-i+1)].a;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==x){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
