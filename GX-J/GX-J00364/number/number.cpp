#include <bits/stdc++.h>
using namespace std;
long long ans[1000000],cnt=-1;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]>='0'&&s[i]<='9')
            ans[cnt+1]=s[i]-'0',cnt++;
    }
    sort(ans,ans+cnt);
    for (int i=cnt;i>=0;i--)
        cout<<ans[i];
    cout<<ans[cnt];
    return 0;
}
