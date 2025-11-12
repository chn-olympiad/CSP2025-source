#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n[1000005],ans=0,c,d;
    for(int i=1;i<=1000005;i++){
        cin>>n[i];
        ans++;
        if(!cin>>n[i]){
            break;
        }
    }
    for(int i=1;i<=ans;i++){
        for(int j=2;j<=ans;j++){
            c=max(n[j],n[j-1]),d=min(n[j],n[j-1]);
            n[j-1]=c,n[j]=d;
            c=0,d=0;
        }
    }
    for(int i=1;i<=ans;i++){
        cout<<n[i];
    }
    return 0;
}
