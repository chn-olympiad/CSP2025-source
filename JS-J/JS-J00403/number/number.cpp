#include<bits/stdc++.h>
#define N 1000100
using namespace std;
string s;
int a[N],cnt;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
    }
    sort(a+1,a+cnt+1);
    while(cnt>0) cout<<a[cnt],cnt--;
    return 0;
}
