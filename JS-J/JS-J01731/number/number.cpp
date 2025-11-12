#include<bits/stdc++.h>
using namespace std;
string s,ans;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char x:s){
        if(x>='0'&&x<='9') ans+=x;
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans<<endl;
    return 0;
}
