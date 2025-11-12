#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],s[200][200],mu=1,k=1;
bool cmp(int b,int c){
    if(b<c) return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int num=a[1];
    sort(a+1,a+1+n*m,cmp);
    while(a[mu]!=num){
        mu++;
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                s[j][i]=a[k];k++;
            }
        }
        else{
            for(int j=n;j>=1;j--){

                s[j][i]=a[k];k++;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
            if(s[i][j]==num) cout<<j<<" "<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
