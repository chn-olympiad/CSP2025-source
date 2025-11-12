#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e6+5;
string s;
int n=0;
int ans[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(unsigned int i=0;i<s.size();i++)
    if(s[i]>='0'&&s[i]<='9') ans[++n]=s[i]^48;
    sort(ans+1,ans+n+1,greater<int>());
    for(int i=1;i<=n;i++) cout<<ans[i];
    return 0;
}
