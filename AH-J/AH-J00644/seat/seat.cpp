#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=1e6+5;
const int M=1e9+7;
int a[dd];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n=read(),m=read();
    for(int i=1;i<=n*m;i++)a[i]=read();
    int p=a[1];
    sort(a+1,a+1+n*m,[](int a,int b){return a>b;});int cnt=0;
    while(a[cnt]!=p)cnt++;
    int l=(cnt-1)/n,c=cnt%n;if(!c)c=n;l++;
    if(!(l%2))c=n-c+1;
    cout<<l<<' '<<c;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
