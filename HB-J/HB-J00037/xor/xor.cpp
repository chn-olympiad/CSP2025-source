#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int s[500005];
void f(int x){
    if(x>n)
        return;
    for(int i=0;i<n-x+1;i++){
        int h=1;
        for(int j=i;j<x+i;j++){
            h=(h||s[j]);
        }
        if(h==k){
            ans++;
        }
    }
    f(x+1);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    f(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
