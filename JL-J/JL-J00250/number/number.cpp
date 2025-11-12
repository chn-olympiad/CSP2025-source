#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+7;
int aa[maxn];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len = s.size();
    int under=1;
    for(int i=0;i<len;i++){
        if(s[i]-'0'>=0 and s[i]-'0'<=9){
            aa[under]=s[i]-'0';
            under++;
        }
    }
    sort(aa+1,aa+under);
    for(int i=under-1;i>=1;i--){
        cout<<aa[i];
    }
    return 0;
}
