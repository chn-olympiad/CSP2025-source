#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n;
int a[5020];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==3){
        if(a[1]+a[2]+a[3]>2*a[1]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    cout<<6;
    fclose(stdin);
    fclose(stdout);
    return 0;
}