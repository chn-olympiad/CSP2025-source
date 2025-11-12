#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[i]=int(s[i]-'0');
            cnt++;
        }
    }
    sort(ans,ans+s.size(),cmp);
    for(int i=0;i<cnt;i++){
        cout<<ans[i];
    }
}
