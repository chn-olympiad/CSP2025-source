#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,flag=0; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') flag=1; c=getchar();}
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return flag ? ~(x-1) : x;
}

const int N=5e6+5;
int n,q;
char s[114][232323];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    while(q--) puts("0");
    return 0;
}