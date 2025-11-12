#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int ans[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s+1;
    int j=0;
    for (int i=1;i<=strlen(s+1);i++)
        if ('0'<=s[i]&&s[i]<='9')ans[++j]=(s[i]-'0');
    sort(ans+1,ans+j+1,greater<int>());
    for (int i=1;i<=j;i++)cout<<ans[i];
    return 0;
}
