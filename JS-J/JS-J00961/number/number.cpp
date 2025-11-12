#include <bits/stdc++.h>
using namespace std;
int cnt[250];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
//        {
            ++cnt[s[i]-'0'];
//            for(int i=9;i>=0;i--)
//            {
//                while(cnt[i]--)
//                    cout<<i;
//            }
//
//       }

    }
    for(int j=9;j>=0;j--)
    {
        while(cnt[j]--)
            cout<<j;
    }
//    cout<<"VICTOR"<<endl;
    return 0;
}
