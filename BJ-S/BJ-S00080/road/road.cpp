#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
    int x=0;
    char c=getchar();
    while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
    return x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n=read(),m=read(),k=read();
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++)u[i]=read(),v[i]=read(),w[i]=read();
    long long cnt=0;
    for(int i=0;i<m;i++)cnt+=w[i];
    cout<<cnt;
    return 0;
}
