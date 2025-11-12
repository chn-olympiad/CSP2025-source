#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],n;
unsigned long long ans;
void dfs(int x,int cnt){
    if(x==n){
        int adall=0,almx=0;
        for(int i=1;i<cnt;++i){
            adall+=b[i];
            if(b[i]>almx) almx=b[i];
        }
        if(adall>almx*2) ++ans;
        if(ans==998244353L) ans=0;
        return;
    }
    dfs(x+1,cnt);
    b[cnt]=a[x];
    dfs(x+1,cnt+1);
}
int main(){
    FILE* fi=NULL,*fo=NULL;
    fi=fopen("polygon.in","rr");
    fo=fopen("polygon.out","wr");
    fscanf(fi,"%d",&n);
    for(int i=0;i<n;++i){
        fscanf(fi,"%d",&a[i]);
    }
    dfs(0,1);
    fprintf(fo,"%lld",ans);
    fclose(fi);
    fclose(fo);
    return 0;
}
