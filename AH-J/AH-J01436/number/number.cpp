#include <bits/stdc++.h>
using namespace std;
const int N=1e6+50;
string s,a;
int sum[N],ans,b[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
        {
            ans++;
            sum[ans]=s[i]-'0';
        }
    sort(sum,sum+ans+1);
    while(ans)
    {
        a+='0'+sum[ans];
        ans--;
    }
    cout<<a<<endl;
    return 0;
}
