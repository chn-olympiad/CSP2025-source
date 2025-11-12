#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=2){
        cout<<0;
    }else if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }if(a[1]>=a[2]&&a[1]>=a[3])cout<<(a[3]+a[2]>a[1]);
        else if(a[2]>=a[1]&&a[2]>=a[3])cout<<(a[1]+a[3]>a[2]);
        else cout<<(a[1]+a[2]>=a[3]);
    }else cout<<9;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
