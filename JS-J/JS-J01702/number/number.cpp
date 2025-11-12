#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt=0;
char s[N],t[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9')  t[++cnt]=s[i];
    }
    sort(t+1,t+cnt+1);
    reverse(t+1,t+cnt+1);
    cout<<t+1;
    return 0;
}
