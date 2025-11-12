#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
string s;
int a[100],ans[N],k;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){//O(n) 1e6
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){//O(n^2) 1e6
        while(a[i]){//O(n)
            ans[++k]=i;
            a[i]--;
        }
    }
    for(int i=1;i<=k;i++){//O(n) 1e6
        cout<<ans[i];
    }
    return 0;
}
