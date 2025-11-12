#include<bits/stdc++.h>
using namespace std;
string n;
int cnt=1,ans[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(int(n[i])<97){ans[cnt]=int(n[i])-48; cnt++;}
    }
    cnt--;
    sort(ans+1,ans+cnt+1);
    for(int i=cnt;i>0;i--) cout<<ans[i];
    return 0;
}