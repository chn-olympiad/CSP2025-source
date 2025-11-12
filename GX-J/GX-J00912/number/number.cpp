#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b[10000]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[i]=s[i]-'0';
        }
        else b[i]=-1;
    }
    sort(b,b+s.size());
    for(int i=s.size();i>=0;i--){
            if(b[i]==-1||i==s.size()) continue;
                    cout<<b[i];
    }

return 0;
}
