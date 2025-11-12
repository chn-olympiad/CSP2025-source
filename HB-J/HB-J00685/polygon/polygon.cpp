#include<iostream>
#include<cstdio>
using namespace std;
int ans=0,n,a[505],book[505];
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
void dfs(int cnt,int sum,int maax,int num){
    if(cnt==n+1){
        if(sum>(maax<<1)&&num>=3){
            ++ans;
        }
        return ;
    }
    book[cnt]=1;
    dfs(cnt+1,sum+a[cnt],max(maax,a[cnt]),num+1);
    book[cnt]=0;
    dfs(cnt+1,sum,maax,num);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=rd();
    for(int i=1;i<=n;++i){
        a[i]=rd();
    }
    dfs(1,0,0,0);
    wt(ans);
    return 0;
}