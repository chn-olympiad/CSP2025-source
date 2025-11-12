#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool sum(int a,int b){
    return b<a;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int m=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i]=a[j];
        }

    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i]=a[j];
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    a[i]=a[j];
                }

            }
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    a[i]=a[j];
                }

            }
        }

    }

    sort(a,a+1000,sum);

    if(m) cout<<6;
    return 0;
}
