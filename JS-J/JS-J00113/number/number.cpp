#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
long long len,nlen;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end());
    nlen=a.size();
    for(int i=nlen-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
