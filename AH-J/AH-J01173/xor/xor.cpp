#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,k,a[N],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    if(k==0){
        for(int i=1;i<=n;++i){
            if(a[i]==0){
                ++cnt;
                a[i]=-1;
            }
        }
        int s=0;
        for(int i=1;i<=n-1;++i){
                s=a[i];
            for(int j=i+1;j<=n;++j){
                s^=a[j];
                if(s==k){
                    ++cnt;
                    for(int k=i;k<=j;++k){
                        a[k]=0;
                    }
                    s=0;
                }
            }
        }
        printf("%d",cnt);
    }else{
        for(int i=1;i<=n;++i){
            if(a[i]==k){
                ++cnt;
                a[i]=0;
            }
        }
        int s=0;
        for(int i=1;i<=n-1;++i){
                s=a[i];
            for(int j=i+1;j<=n;++j){
                s^=a[j];
                if(s==k){
                    ++cnt;
                    for(int k=i;k<=j;++k){
                        a[k]=0;
                    }
                    s=0;
                }
            }
        }
        printf("%d",cnt);
    }
    return 0;
}
