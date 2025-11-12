#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int num[100][100];
int list_[10000];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int ans=0;int cnt=1;
    int n,m;cin>>n>>m;bool p=1;
    for(int i=1;i<=n*m;i++){
        cin>>list_[i];
    }ans=list_[1];
    sort(list_+1,list_+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(p){
            for(int j=1;j<=m;j++){
                if(list_[cnt]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }else {
                    num[i][j]=list_[cnt];cnt++;
                }
            }p=0;
        }else {
            for(int j=m;j>0;j--){
                if(list_[cnt]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }else {
                    num[i][j]=list_[cnt];cnt++;
                }
            }p=1;
        }
    }
    return 0;
}

