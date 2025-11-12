#include <bits/stdc++.h>

using namespace std;

const int maxn=10;
int hush[maxn];

string s;

void init()
{
    cin>>s;
    memset(hush,0,sizeof(hush));
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            hush[s[i]-'0']++;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    init();
    for(int i=9;i>=0;i--)
        if(hush[i]>0)
            while(hush[i]--)
                cout<<i;
    return 0;
}
