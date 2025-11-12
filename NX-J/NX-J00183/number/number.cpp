#include<bits/stdc++.h>
using namespace std;
string s;
long long t=1;
long long ans[10010];
bool cmp(long long q,long long h){
    return q>h;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[t]=s[i]-48;
            t++;
        }
    }
    sort(ans+1,ans+t+1,cmp);
    for(int i=1;i<=t-1;i++){
        printf("%d",ans[i]);
    }
    return 0;
}
