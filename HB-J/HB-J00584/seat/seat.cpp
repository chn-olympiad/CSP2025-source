#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    if(a>b)return true;
    else return false;
}

int main(){
    int n,m;//n hang; m lie
    int l[n+1][m+1]={};
    int s[m*n+1];
    int xr;
    freopen("seat.in","r",stdin);
    cin>>n>>m;
    
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    fclose(stdin);
    xr=s[0];
    sort(s,s+m*n+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                l[j][i]=s[(i-1)*n+j];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                l[j][i]=s[(i-1)*n+n-j+1];
            }
        }
    }
    int c,r,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(l[i][j]==xr) {
                c=j,r=n;
                flag=1;
                break;
            }
            if(flag==1)break;
        }
    }
    freopen("seat.out","w",stdout);
    cout<<c<<' '<<r;
    fclose(stdout);
    return 0;
}