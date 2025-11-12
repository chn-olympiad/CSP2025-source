#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    cin>>s;
    vector<char> f;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<'a')
        {
            f.push_back(s[i]);
        }
    }
    sort(f.rbegin(),f.rend());
    for(int i=0;i<f.size();i++)
    {
        cout<<f[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
