#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
char a[1000005];
int cnt=0;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[cnt]=s[i];
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>0;i--){
        cout<<a[i];
    }
    return 0;
}
