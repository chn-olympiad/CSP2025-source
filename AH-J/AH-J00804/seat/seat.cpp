#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 1005
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[MAXN],x,id,lie,hang;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]){
            id=i;
            break;
        }
    }
    lie=(id%n)?(id/n+1):(id/n);
    if(lie%2){
        hang=id%n;
        if(!hang){
            hang=n;
        }
    }else{
        hang=n-id%n+1;
        if(hang>n){
            hang=1;
        }
    }
    cout<<lie<<" "<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
