#include<bits/stdc++.h>
using namespace std;
long long cnt[128];
char s[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s+1;
    int l=strlen(s+1);
    for(int i=1;i<=l;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            cnt[s[i]]++;
        }
    }
    bool flag=false;
    //for(int i=127;i>=0;i--) cout<<cnt[i]<<endl;
    for(int i='9';i>='1';i--)
        for(int j=cnt[i];j>0;j--)
            printf("%c",i),flag=1;
    if(flag==1) for(int j=cnt['0'];j>0;j--) printf("0");
    return 0;
}
