#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];int cnt;
int n;string s;
bool is_num(char c)
{
    if('0'<=c and c<='9') return true;
    else return false;
}
bool cmp(int x,int y){return x>y;}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(is_num(s[i]))
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) cout<<a[i];
    cout<<'\n';
    return 0;
}