#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],tot;
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[++tot]=s[i]-'0';
    }
    sort(a+1,a+1+tot);
    for(int i=tot;i>=1;i--) cout<<a[i];
    return 0;
}
//#Shang4Shan3Ruo6Shui4
