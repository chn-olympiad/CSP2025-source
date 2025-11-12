#include<bits/stdc++.h>
using namespace std;
string x;
int ans[1000006],len=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>x;
    for(int i=0;i<x.size();i++){
        if(x[i]>='0'&&x[i]<='9') ans[++len]=x[i]-'0';
    }

    sort(ans+1,ans+len+1);

    if(ans[len]==0){
        cout<<"0";
    }
    else{
        for(int i=len;i>=1;i--) cout<<ans[i];
    }

    return 0;
}
