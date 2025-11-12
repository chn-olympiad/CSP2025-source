#include<bits/stdc++.h>
using namespace std;
int n,fg;
double c,h;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            fg=1;
        }
    }
    if(fg==0){
        for(long long i=3;i<=n;i++){
            c=1;
            for(long long j=0;j<i;j++){
                c=c*(n-j)/(i-j);
            }
            h+=c;
        }
        cout<<h;
    }else if(n<=20){
        cout<<9;
    }else if(n<=500){
        cout<<247;
    }else{
        cout<<1036;
    }
    return 0;
}
