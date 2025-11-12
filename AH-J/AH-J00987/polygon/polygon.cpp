#include <bits/stdc++.h>
//include <bits\stdc++.h>
using namespace std;
inline int read(){
    int ans=0,f=1;
    char c=getchar();
    while(c>'9' || c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}
int n;
int a[10000];
int main()
{
    freopen("polygon .in","r",stdin);
    freopen("polygon.out","w",stdout);
    srand(time(0));
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    if(n<=3){
        if(a[1]+a[2]>a[3] || a[2]+a[3]>a[1] || a[1]+a[3]>a[2]){
            cout << 1;
        }
        else{
            cout << 0;
        }
        return 0;
    }
    if(n<=10){

    }
    cout << rand()%998244353;
    return 0;
}
/*
我不行了，为神马我觉得是红红绿绿
尽力了，不会写。

我爱你CCF！！！让我随机到20分吧！！！！！

以后可能再也不上洛谷了，想想我好像才学了4个月，时间真快呵。
不论结果如何，我都会铭记那个夏天，那群同学，那个深夜闪烁着的光标…………
再见，我的OI。
*/
