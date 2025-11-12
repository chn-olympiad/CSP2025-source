#include<bits/stdc++.h>
using namespace std;

long long ans[1000010];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    int k=0;
    cin >> s;
    for(int i=0;i<=s.size()+1;i++){
        if(s[i]=='0' || s[i]=='1' || s[i]== '2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
            ans[k] = s[i]-'0';
            k++;
        }
    }
    sort(ans,ans+k);
    for(int i=k-1;i>=0;i--){
        cout << ans[i];
    }
    return 0;
}
