#include<bits/stdc++.h>
using namespace std;
int m;
int a[5005];
int b(int x,int maxx,int he){
    if(2*maxx>=he+a[x]) return 0;
    int ans=0;
    for(int i=x+1;i<m;i++){
        ans+=b(i,max(maxx,a[i]),he+a[i]);
    }
    return 1+ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    if(m<=2){
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans+=b(i+1,a[i],a[i]);
    }
    cout<<ans;
    return 0;
}
