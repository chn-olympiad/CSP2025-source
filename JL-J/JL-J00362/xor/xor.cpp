#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
long long cnt=0;
long long ans=0;
const int N=5e5+5;
long long a[N],n,k;
long long c[N];
struct an{
    long long l,r,len;
}p[N];
bool cmp(an x,an y){
    return x.len<y.len;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(i==1) c[i]=a[i];
        else c[i]=c[i-1]^a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int j=c[r]^c[l-1];
            if(j==k){
                p[++cnt].l=l,p[cnt].r=r;
                p[cnt].len=r-l+1;
            }
        }
    }
    sort(p+1,p+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        int f=0;
        for(int j=p[i].l;j<=p[i].r;j++){
            if(a[j]==-1){
               f=1;
               break;
            }
        }
        if(f) continue;
        for(int j=p[i].l;j<=p[i].r;j++){
            a[j]=-1;
        }
        ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
