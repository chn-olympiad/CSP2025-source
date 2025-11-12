#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define el '\n'
Int read()
{
    Int s=1,d=0;
    char chat=getchar();
    while(chat<'0'||chat>'9')
    {
        if(chat=='-') s=-1;
        chat=getchar();
    }
    while(chat>='0'&&chat<='9')
    {
        d=d*10+chat-'0';
        chat=getchar();
    }
    return s*d;
}
int n,k,xors[500005];
Int cnt;
int main()
{
    //xor
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(); k=read();
    int in=0;
    for(int i=1;i<=n;++i) in=read(),xors[i]=(xors[i-1]^in);
    int i=1,j=1;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j++)
            if((xors[j]^xors[i-1])==k)
            {
                cnt++;
                i=j;
                break;
            }
    cout<<cnt<<el;
    return 0;
}
