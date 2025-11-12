#include<bits/stdc++.h>
using namespace std;
int a[100050],b[100050],c[100050],a_b[100050],a_c[100050],b_c[100050],b_a[100050],c_a[100050],c_b[100050],vis[100050];
int t;
int find_maxab(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(a_b[i]<=0 && a_b[i]>maxn && vis[i]==0) {
            maxn=a_b[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int find_maxac(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(a_c[i]<=0 && a_c[i]>maxn && vis[i]==0) {
            maxn=a_c[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int find_maxba(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(b_a[i]<=0 && b_a[i]>maxn && vis[i]==0) {
            maxn=b_a[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int find_maxbc(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(b_c[i]<=0 && b_c[i]>maxn && vis[i]==0) {
            maxn=b_c[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int find_maxca(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(c_a[i]<=0 && c_a[i]>maxn && vis[i]==0) {
            maxn=c_a[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int find_maxcb(int n){
    int maxn=-1e9,di=0;
    for(int i=1;i<=n;i++){
        if(c_b[i]<=0 && c_b[i]>maxn && vis[i]==0) {
            maxn=c_b[i];
            di=i;
        }
    }
    vis[di]=1;
    return maxn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        int n;
        cin>>n;
        memset(vis,0,sizeof(vis));
        int max_sum=0,cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int tmp=max(a[i],max(b[i],c[i]));
            max_sum+=tmp;
            if(tmp==a[i]){
                cnta++;
                a_b[i]=-1e9;
            a_c[i]=-1e9;
            b_c[i]=-1e9;
            b_a[i]=b[i]-a[i];
            c_a[i]=c[i]-a[i];
            c_b[i]=-1e9;
            }
            else if(tmp==b[i]){
                cntb++;
                a_b[i]=a[i]-b[i];
            a_c[i]=-1e9;
            b_c[i]=-1e9;
            b_a[i]=-1e9;
            c_a[i]=-1e9;
            c_b[i]=c[i]-b[i];
            }
            else{
                cntc++;
                a_b[i]=-1e9;
            a_c[i]=a[i]-c[i];
            b_c[i]=b[i]-c[i];
            b_a[i]=-1e9;
            c_a[i]=-1e9;
            c_b[i]=-1e9;
            }

        }

        while(cnta>n/2){
            max_sum+=max(find_maxba(n),find_maxca(n));
            cnta--;
        }
        while(cntb>n/2){
            max_sum+=max(find_maxab(n),find_maxcb(n));
            cntb--;
        }
        while(cntc>n/2){
            max_sum+=max(find_maxac(n),find_maxbc(n));
            cntc--;
        }
        cout<<max_sum<<endl;
    }
    return 0;
}