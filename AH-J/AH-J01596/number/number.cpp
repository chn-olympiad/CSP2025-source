#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            s.erase(i,1);
            i--;
        }
    }
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
