#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
string s;
int a[N],cnt=0;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);

    for(int i=cnt;i>=1;i--){
        if(i==cnt&&a[i]==0){
            cout<<0;
            return 0;
        }
        cout<<a[i];
    }
    return 0;
}
