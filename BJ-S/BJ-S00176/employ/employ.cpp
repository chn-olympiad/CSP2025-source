#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int c=0,x=1;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            x=-1;
        }
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c*x;
}

int n,m;
bool a[505];
int ans,sum;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=getchar()-'0';
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){

    }

    return 0;
}
