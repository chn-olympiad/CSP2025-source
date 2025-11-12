#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int ans[N],tot;
bool cmp(int a,int b){return a>b;}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            tot++;
            ans[tot]=s[i]-'0';
        }
    }
    sort(ans+1,ans+tot+1,cmp);
    for(int i=1;i<=tot;i++) cout<<ans[i];
    return 0;
}
