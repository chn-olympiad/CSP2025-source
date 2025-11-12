#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[200005];
int rd(){
    int f=1,x=0;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void wt(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        wt(x/10);
    }
    putchar(x%10+'0');
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=rd();
    k=rd();
    for(int i=1;i<=n;++i){
        a[i]=rd();
    }
    if(k<=1){
        int ans=0;
        if(k==1){
            for(int i=1;i<=n;++i){
                if(a[i]==1)++ans;
            }
            wt(ans);
        }else{
            bool f=false;
            for(int i=1;i<=n;++i){
                if(a[i]==0){
                    f=false;
                    ++ans;
                }else{
                    if(f==false){
                        f=true;
                    }else{
                        ++ans;
                        f=false;
                    }
                }
            }
            wt(ans);
        }
    }
    return 0;
}