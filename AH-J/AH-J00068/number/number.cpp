#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,num[1000005];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
        if(s[i]>='0'&&s[i]<='9')
            num[++cnt]=s[i]^48;
    sort(num+1,num+1+cnt);
    if(num[cnt]==0) cout<<0;
    else for(int i=cnt;i;i--) cout<<num[i];
    return 0;
}
