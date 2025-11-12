#include<bits/stdc++.h>
using namespace std;
int n,b=3;
long long s,a[5005],c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c=max(c,a[i]);
    }
    if(n<=3){
        if(a[1]+a[2]+a[3]>c*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}

