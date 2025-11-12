#include <bits/stdc++.h>

using namespace std;
int read();
void write(int x);
int n,k,a[500005],d[500005],ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();

    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
            int zhi=a[i];if(zhi==k){ans++;continue;}
        for(int j=i+1;j<=n;j++){
            zhi=(zhi^a[j]);
            if(zhi==k){
                i=j+1;
                ans++;
                break;
            }
        }
    }
    write(ans);
    return 0;
}
int read(){
    int x,y=1;char c;
    while((c=getchar())>'9'||c<'0') if(c=='-') y=-1;
    x=(c^48);
    while ((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
