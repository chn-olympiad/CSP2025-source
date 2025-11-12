#include<bits/stdc++.h>
using namespace std;
int b[1000009];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int ans,n=0;
    int x=1;
    cin>>a;
    for(int i=0;i<a.length();i++){
        ans=a[i];
        ans=ans-48;
        if(ans<10&&ans>=0){
            b[x]=ans;
            n++;
            x++;
        }
    }
    sort(b,b+n+1);
    for(int i=n;i>=1;i--){
        cout<<b[i];
    }
    return 0;
}
