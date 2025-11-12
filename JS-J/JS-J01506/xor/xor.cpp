#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w,ans,a[500005],v[30],b[30];
inline int read(){
    int f=1,c=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){c=(c<<1)+(c<<3)+(ch^48);ch=getchar();}
    return c*f;
}
inline void xxj(int x){
    for(int i=21;i>=0;i--){
        if(x>>i){
            w=max(w,i);
            if(v[i]!=0)x^=v[i];
            else{
                v[i]=x;
                return;
            }
        }
    }
    return;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);cout.tie(0);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(m==0){
		for(int i=1;i<=n;i++){
			xxj(a[i]);
			int fl=0;
			for(int i=0;i<=w;i++)
				for(int j=i;j<=w;j++){
					int sum=0;
					for(int k=i;k<=j;k++)sum^=v[k];
					if(sum==m){fl=1;break;}
				}
			if(fl==1){
				ans++;w=0;
				for(int i=0;i<=w;i++)v[i]=0;
			}
		}
        printf("%lld",ans);
        return 0;
    }
    for(int p=1;p<=n;p++){
        xxj(a[p]);
        for(int i=0;i<=w;i++)b[i]=v[i];
        xxj(m);
        bool fl=0;
        for(int i=0;i<=w;i++)
            if(b[i]!=v[i]){fl=1;break;}
        if(fl==1){
            for(int i=0;i<=w;i++)
                v[i]=b[i];
        }
        else{
            for(int i=0;i<=w;i++)v[i]=b[i]=0;
            w=0;ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}