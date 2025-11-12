#include<bits/stdc++.h>
using namespace std;
long long cnt[20]={0};
string s;
int main(void)
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        if(s[i]>='0' && s[i]<='9')
            cnt[s[i]-'0']++;
    for(long long i=9;i>=0;i--)
        for(long long j=1;j<=cnt[i];j++)
            cout<<i;
    cout<<s;
    return 0;
}
//AFO ji4

//wo3 yao3 shang4 mi2 huo4 xing3 wei2 da4 shang3!!!
//Luogu uid:1057768xingwei
