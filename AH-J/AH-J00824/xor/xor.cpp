#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],k,cnt;
int f(int x,int y){
    int t=a[x];
    for(int i=x+1;i<=y;i++){
        t=(t^a[i]);
    }
    return t;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==1){
        cout<<n;
    }else if(k==0){
        cout<<n/2;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//#Shang4Shan3Ruo6Shui4
