#include<bits/stdc++.h>
using namespace std;
int a[5001],c[5001],top=0,ans=0;
int n;
void f(int b){
    for(int i=b;i<=n;i++){
        top++;
        c[top]=a[i];
        int tmp=0,tmp2=0;
        for(int j=1;j<=top;j++){
            tmp+=c[j];
            tmp2=max(tmp2,c[j]);
        }
        if(tmp>tmp2*2)ans++;
        f(i+1);
        c[top]=0;
        top--;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(1);
    cout<<ans;
    return 0;
}
