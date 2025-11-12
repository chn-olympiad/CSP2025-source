#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int l[3];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        int l=read();
        a[i]=l;
    }
    if(k<=1){
        for(int i=1;i<=n;i++){
            int p=a[i];
            if(p==0) l[0]++;
            if(p==1) l[1]++;
        }
        if(k==0){
            cout<<l[0]+l[1]/2<<'\n';
        }else{
            cout<<l[1]+l[0]/2<<'\n';
        }
    }else{
        return 0;
    }
    return 0;
}
