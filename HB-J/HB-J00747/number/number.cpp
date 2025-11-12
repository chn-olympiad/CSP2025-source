#include<bits/stdc++.h>
using namespace std;

int read()
{
    char ch=getchar();
    int x=0,f=1;
    while (!isdigit(ch))
    {
        if (ch=='-') f=-f;
        ch=getchar();
    }
    while (isdigit(ch))
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int b[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();

    for (int i=0;i<l;i++) if (isdigit(s[i])) b[s[i]^48]++;
    for (int i=9;i>=0;i--)
    {
        while (b[i]--) putchar(i^48);
    }
    cout<<"\n";
}
