#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005];
bool comp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int n=1;
    for(int i=0;i<s.size();i++){
        char x=s[i];
        if(int(x)>=48&&int(x)<=57){
            int c=int(x)-48;
            ans[n]=c;
            ++n;
        }
    }
    sort(ans+1,ans+n,comp);
    for(int i=1;i<=n-1;i++)
        cout<<ans[i];
    return 0;
}