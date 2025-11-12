#include <bits/stdc++.h>
using namespace std;
char a;
int m[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a)
        if(a>='0' && a<='9')
            m[a-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=m[i];j++)
            cout<<i;
    return 0;
}
//lai le san ci CSP le
//zong yao shang ji ci <<qi pa xing wei da shang ba>>
//hen gao xing yi zhe yang de fang shi ren shi ni , mo sheng ren
//zhu ni RP++ , tian tian jin bu !