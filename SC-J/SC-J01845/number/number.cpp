#include<bits/stdc++.h>
using namespace std;

ifstream fin("number.in");
ofstream fout("number.out");
string s;
int cnt[11];

int main()
{
    // freopen("number.in","r",stdin);
    // freopen("number.out","w",stdout);
    fin>>s;
    for(char c:s)
        if('0'<=c&&c<='9')
            ++cnt[c-'0'];
    for(int i=9;i>=0;i--)
        while(cnt[i]--)
            fout<<i;
    fout<<"\n";
}