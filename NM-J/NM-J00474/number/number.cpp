#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int ans[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int x=int(s[i]-'0');
            ans[x]++;
        }
    }
    bool k=0;
    for(int i=9;i>=0;i--){
        if(i==0&&k==0){
            cout<<0<<'\n';
            return 0;
        }
        while(ans[i]>=1){
            cout<<i;
            ans[i]--;
            k=1;
        }
    }
    return 0;
}
