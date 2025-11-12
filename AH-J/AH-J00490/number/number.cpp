#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt;
char c[10000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            c[i]=s[i];
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            if(c[j]<c[j+1])
            {
                swap(c[j],c[j+1]);
            }

        }
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<c[i];
    }
    return 0;
}
