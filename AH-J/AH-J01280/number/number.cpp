#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int l=s.length();
    int j=0;
    vector<int>v(l);
    for(int i=0;i<l;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            v[j]=s[i]-'0';
            j++;
        }
    }
    sort(v.begin(),v.end());
    for(int i=l-1;i>=l-j;i--)cout<<v[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
