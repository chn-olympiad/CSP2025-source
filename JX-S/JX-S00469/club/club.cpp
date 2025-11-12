#include<iostream>
#include<algorithm>
using namespace std;
int T;
void solve(){
    int n;
    scanf("%d",&n);
    int a[n+1],b[n+1],c[n+1];
    bool p1=true;
    bool p2=true;
    bool p3=true;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",a+i,b+i,c+i);
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=0||c[i]!=0) p1=false;
        if(a[i]!=0||c[i]!=0) p2=false;
        if(b[i]!=0||a[i]!=0) p3=false;
    }
    if(p1){
        sort(a+1,a+n+1);
        int y=n/2;
        int sum=0;
        for(int i=n;i>y;i--) sum+=a[i];
        cout<<sum<<endl;
    }else if(p2){
        sort(b+1,b+n+1);
        int y=n/2;
        int sum=0;
        for(int i=n;i>y;i--) sum+=b[i];
        cout<<sum<<endl;
    }else if(p3){
        sort(c+1,c+n+1);
        int y=n/2;
        int sum=0;
        for(int i=n;i>y;i--) sum+=c[i];
        cout<<sum<<endl;
    }else if(n==2){
        int maxn=-1;
        maxn=max(maxn,a[1]+b[2]);
        maxn=max(maxn,a[1]+c[2]);
        maxn=max(maxn,a[2]+b[1]);
        maxn=max(maxn,a[2]+c[1]);
        cout<<maxn<<endl;
    }else if(n==4){
        int maxn=-1;
        maxn=max(maxn,a[1]+a[2]+b[3]+b[4]);
        maxn=max(maxn,a[1]+a[2]+b[3]+c[4]);
        maxn=max(maxn,a[1]+a[2]+c[3]+c[4]);
        maxn=max(maxn,a[1]+b[2]+a[3]+b[4]);
        maxn=max(maxn,a[1]+b[2]+a[3]+c[4]);
        maxn=max(maxn,a[1]+b[2]+a[3]+c[4]);
        maxn=max(maxn,a[1]+b[2]+b[3]+a[4]);
        maxn=max(maxn,a[1]+b[2]+b[3]+c[4]);
        maxn=max(maxn,a[1]+b[2]+c[3]+a[4]);
        maxn=max(maxn,a[1]+b[2]+c[3]+b[4]);
        maxn=max(maxn,b[1]+a[2]+a[3]+b[4]);
        maxn=max(maxn,b[1]+a[2]+a[3]+c[4]);
        maxn=max(maxn,b[1]+a[2]+b[3]+a[4]);
        maxn=max(maxn,b[1]+a[2]+b[3]+c[4]);
        maxn=max(maxn,b[1]+a[2]+c[3]+a[4]);
        maxn=max(maxn,b[1]+a[2]+c[3]+b[4]);
        maxn=max(maxn,b[1]+a[2]+c[3]+c[4]);
        maxn=max(maxn,b[1]+b[2]+a[3]+a[4]);
        maxn=max(maxn,b[1]+b[2]+a[3]+c[4]);
        maxn=max(maxn,b[1]+b[2]+c[3]+c[4]);
        maxn=max(maxn,b[1]+b[2]+c[3]+a[4]);
        maxn=max(maxn,b[1]+c[2]+a[3]+a[4]);
        maxn=max(maxn,b[1]+c[2]+a[3]+b[4]);
        maxn=max(maxn,b[1]+c[2]+a[3]+c[4]);
        maxn=max(maxn,b[1]+c[2]+b[3]+a[4]);
        maxn=max(maxn,b[1]+c[2]+b[3]+c[4]);
        maxn=max(maxn,b[1]+c[2]+c[3]+a[4]);
        maxn=max(maxn,b[1]+c[2]+c[3]+b[4]);
        maxn=max(maxn,c[1]+a[2]+a[3]+b[4]);
        maxn=max(maxn,c[1]+a[2]+a[3]+c[4]);
        maxn=max(maxn,c[1]+a[2]+b[3]+a[4]);
        maxn=max(maxn,c[1]+a[2]+b[3]+b[4]);
        maxn=max(maxn,c[1]+a[2]+b[3]+c[4]);
        maxn=max(maxn,c[1]+a[2]+c[3]+a[4]);
        maxn=max(maxn,c[1]+a[2]+c[3]+b[4]);
        maxn=max(maxn,c[1]+b[2]+a[3]+a[4]);
        maxn=max(maxn,c[1]+b[2]+a[3]+b[4]);
        maxn=max(maxn,c[1]+b[2]+b[3]+c[4]);
        maxn=max(maxn,c[1]+b[2]+c[3]+a[4]);
        maxn=max(maxn,c[1]+c[2]+a[3]+a[4]);
        maxn=max(maxn,c[1]+c[2]+a[3]+b[4]);
        maxn=max(maxn,c[1]+c[2]+b[3]+a[4]);
        maxn=max(maxn,c[1]+c[2]+b[3]+b[4]);
        cout<<maxn<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
