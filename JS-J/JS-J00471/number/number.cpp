#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+10;
string s;
ll idx=1,a[M],f[12];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[idx]=s[i]-'0';
            idx++;
        }
    }
    for(int i=1;i<idx;i++)
    {
        f[a[i]]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=f[i];j++) cout<<i;
    }
    return 0;
}
