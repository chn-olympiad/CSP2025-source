#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[1000005];
vector<int> t;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    for(int i=1;s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9';i++)if(s[i]>='0'&&s[i]<='9')t.push_back(s[i]-'0');
    sort(t.begin(),t.end());
    for(int i=t.size()-1;i>-1;i--)printf("%lld",t[i]);
    return 0;
}
