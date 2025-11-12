#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,r,z;
int a[205],c;
int s[205][205];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    z=n*m;
    sort(a+1,a+z+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                c++;
                s[i][j]=a[c];
            }
        }else{
            for(int k=n;k>=1;k--){
                c++;
                s[k][j]=a[c];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==r){
                cout<<j<<" "<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
