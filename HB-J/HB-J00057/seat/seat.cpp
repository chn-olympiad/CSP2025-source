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
Int n,m,grade[105];
int main()
{
    //seat
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    n=read();
    m=read();
    for(Int i=1;i<=n*m;++i) grade[i]=read();
    Int date=grade[1];
    stable_sort(grade+1,grade+n*m+1,greater<int>());
    Int pos=lower_bound(grade+1,grade+n*m+1,date,greater<int>())-grade;
    Int ch=pos/n,Mod=pos%n;
    if(ch&1) cout<<ch+1<<' '<<n-Mod+1<<el;
    else cout<<ch+1<<' '<<Mod<<el;
    return 0;
}

