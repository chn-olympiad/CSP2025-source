#include<bits/stdc++.h>
using namespace std;
int a[100],n,m,cnt=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2&&a[i]!=a[i-1]){
            cnt=0;
		}
    }
    if(cnt||n<=2){
        cout<<0;
    }
    if(n==3){
        if(a[1]<a[2]+a[3]&&a[2]>a[1]+a[3]&&a[3]>a[1]+a[2])){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
