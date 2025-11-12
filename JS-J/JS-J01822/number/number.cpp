#include<bits/stdc++.h>
using namespace std;
int ans[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int len=s.size(),cnt=0;;
    for(int i=0;i<len;i++){
        char x=s[i];
        if(x>='0'&&x<='9'){
            ans[++cnt]=x-'0';
        }
    }
    sort(ans+1,ans+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout<<ans[i];
    }
    return 0;
}
