#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e6+10;
int n,t[11];
char s[N];
bool f;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s+1,n=strlen(s+1);
    for(int i=1;i<=n;i++)
    if(s[i]>='0'&&s[i]<='9')
    t[s[i]-'0']++;
    for(int i=9;i>=0;i--){
        if(t[i]>0&&i){
            f=true;
            while(t[i]--)cout<<i;
        }
        if(t[i]>0&&!i){
            if(f)while(t[i]--)cout<<0;
            else cout<<0;
        }
    }
    return 0;
}