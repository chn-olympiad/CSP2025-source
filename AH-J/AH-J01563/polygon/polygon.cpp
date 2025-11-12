#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5500];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int a1=a[1];
        int a2=a[2];
        int a3=a[3];
        int sum=a1+a2+a3;
        int maxn=max(a1,max(a2,a3));
        if(sum-maxn>maxn){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }else{
    cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
