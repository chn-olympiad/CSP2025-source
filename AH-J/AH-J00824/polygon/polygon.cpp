#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,s,u,v,r;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]<a[2]+a[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//#Shang4Shan3Ruo6Shui4

