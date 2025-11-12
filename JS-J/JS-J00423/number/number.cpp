#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    string n;
    string ans="";
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9'){
            ans+=n[i];
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    cout << ans;
    return 0;
}
