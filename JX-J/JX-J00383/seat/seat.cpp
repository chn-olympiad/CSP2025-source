#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,js=1,zh;
    cin>>n>>m;
    int a[101]={};
    int a1[n+1][m+1]={};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    zh=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            a1[i][j]=a[js];
            js++;
        }
    }
    for(int j=1;j<=m;j++){
        if(j%2!=0){
            continue;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int i1=1;i1<n;i1++){
                    if(a1[i1][j]>a1[i1+1][j])swap(a1[i1][j],a1[i1+1][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(zh==a1[i][j]){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
