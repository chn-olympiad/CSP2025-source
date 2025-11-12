#include<bits/stdc++.h>
using namespace std;
int t,n,s0,s1;
int a[100005],b[100005],c[100005],a1[100005];
void f(int k,int x,int y,int z){
    if(k>n){
        s1=max(s0,s1);
        return;
    }
    if(s0+(a1[n]-a1[k-1])<s1) return;
    int mi=min(min(n/2-x,n/2-y),n/2-z);
    if(mi>=n-(k-1)){
        int s3=0;
        for(int i=k;i<=n;i++)
            s3+=max(max(a[i],b[i]),c[i]);
        s1=max(s0+s3,s1);
        return;
    }
    if(x<n/2){
        s0+=a[k];
        f(k+1,x+1,y,z);
        s0-=a[k];
    }
    if(y<n/2){
        s0+=b[k];
        f(k+1,x,y+1,z);
        s0-=b[k];
    }
    if(z<n/2){
        s0+=c[k];
        f(k+1,x,y,z+1);
        s0-=c[k];
    }
}
bool cmp(int a,int b){
    return (a>=b);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int u=1;u<=t;u++){
        scanf("%d",&n);
        int flag=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            a1[i]=a1[i-1]+max(max(a[i],b[i]),c[i]);
            if(b[i]>0||c[i]>0) flag=0;
        }
        s0=s1=0;
        if(flag){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++)
                s1+=a[i];
            printf("%d\n",s1);
        }
        f(1,0,0,0);
        printf("%d\n",s1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
