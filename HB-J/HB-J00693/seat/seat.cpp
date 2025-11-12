#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int k;
int r;
int id;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++k];
            if(k==1){
                r=a[k];
            }
        }
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
        if(a[i]==r){
            id=i;
            break;
        }
    }
    int c=n*m;
    int i=1,j=1;
    while(c--){
        if(c==id){
            cout<<j<<" "<<i;
        }
        if(i==1&&j%2==0||i==n&&j%2==1){
            j++;
            continue;
        }
        if(j%2==0){
            i--;
        }else{
            i++;
        }
    }
    return 0;
}
