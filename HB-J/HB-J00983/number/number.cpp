#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
int t[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cout<<s[i];
        }
    }
    return 0;
}
//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
//happy halloween!
//I'm Kremlin897! luogu:1046158
