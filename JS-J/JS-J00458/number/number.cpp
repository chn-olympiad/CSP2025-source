#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long rp=-1;
string s;
int t[15],n;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;n=s.size();
    for(int i=0;i<n;i++)t[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=t[i];j++)cout<<i;
    return 0;
}

//mo bai xst dalao!
//mo bai wyx dalao!
//mo bai cyh dalao!
//#Shang4Shan3Ruo6Shui4
