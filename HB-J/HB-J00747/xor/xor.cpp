#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<20)+10;
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
int s[500010];
bool hav[maxn];
int ans[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n=read(),k=read();
    for (int i=1;i<=n;i++) s[i]=read();
    for (int i=1;i<=n;i++) s[i]^=s[i-1];
    //for (int i=1;i<=n;i++) cout<<s[i]<<' ';
    //cout<<"\n";
    int a=0;
    for (int i=0;i<=n;i++)
    {
		int no=0,p=(s[i]^k);
        if (hav[p]) no=ans[p]+1;
        no=max(no,a);
        hav[s[i]]=1;
        //cout<<"I am the "<<i<<".Num:"<<s[i]<<".Find:"<< (s[i]^k) <<".The ans is:"<<ans[s[i]^k]<<".So my dp is:"<<no<<"\n";
        ans[s[i]]=max(ans[s[i]],no);
        a=max(a,no);
    }
    cout<<a<<"\n";
}
