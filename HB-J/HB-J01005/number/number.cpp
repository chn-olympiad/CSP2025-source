#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int ans[N],k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0') ans[++k]+=s[i]-'0';
    }
    sort(ans+1,ans+k+1,cmp);
    for(int i=1;i<=k;i++) cout<<ans[i];
    return 0;
}
