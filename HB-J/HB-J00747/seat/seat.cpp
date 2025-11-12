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
int s[1005];

bool cmp(int a,int b){return a>b;}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=read(),m=read();
    int t=n*m;
    for (int i=1;i<=t;i++) s[i]=read();
    int f=s[1];
    sort(s+1,s+1+t,cmp);
    int p=0;
    for (int i=1;i<=t;i++) if (s[i]==f) p=i;
	
    int r=0,l=0;//r lie l hang
    r=((p-1)/(n<<1));
    p-=r*(n<<1);
    r<<=1;
    r++;
    if (p>n) r++,l=n-(p-n)+1;
    else l=p;
    cout<<r<<' '<<l<<"\n";
}
