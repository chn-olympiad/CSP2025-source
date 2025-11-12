#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,tot1,tot2,tot3;
struct node{
    int maxn1,maxn2,p;
}a[N],b[N],c[N];
void init(){
    for(int i=1;i<=n;i++) a[i]=b[i]=c[i]={0,0,0};
    tot1=tot2=tot3=0;
    return;
}

bool cmp(node x,node y){
    return x.p > y.p;
}

int main(){
    //freopen("club.in","w",stdout);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        init();
        cin>>n;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            if(a1>=a2 && a1>=a3){
                a[++tot1].maxn1=a1;
                if(a2>=a3) a[tot1].maxn2=a2;
                else a[tot1].maxn2=a3;
                a[tot1].p=a[tot1].maxn1-a[tot1].maxn2;
            }
            else if(a2>=a1 && a2>=a3){
                b[++tot2].maxn1=a2;
                if(a1>=a3) b[tot2].maxn2=a1;
                else b[tot2].maxn2=a3;
                b[tot2].p=b[tot2].maxn1-b[tot2].maxn2;
            }
            else if(a3>=a1 && a3>=a2){
                c[++tot3].maxn1=a3;
                if(a1>=a2) c[tot3].maxn2=a1;
                else c[tot3].maxn2=a2;
                c[tot3].p=c[tot3].maxn1-c[tot3].maxn2;
            }
        }
        long long ans=0;
        if(tot1 > n/2){
            sort(a+1,a+tot1+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=a[i].maxn1;
            for(int i=n/2+1;i<=tot1;i++) ans+=a[i].maxn2;
            for(int i=1;i<=tot2;i++) ans+=b[i].maxn1;
            for(int i=1;i<=tot3;i++) ans+=c[i].maxn1;
        }
        else if(tot2 > n/2){
            sort(b+1,b+tot2+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=b[i].maxn1;
            for(int i=1;i<=tot1;i++) ans+=a[i].maxn1;
            for(int i=n/2+1;i<=tot2;i++) ans+=b[i].maxn2;
            for(int i=1;i<=tot3;i++) ans+=c[i].maxn1;
        }
        else if(tot3 > n/2){
            sort(c+1,c+tot3+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=c[i].maxn1;
            for(int i=1;i<=tot1;i++) ans+=a[i].maxn1;
            for(int i=1;i<=tot2;i++) ans+=b[i].maxn1;
            for(int i=n/2+1;i<=tot3;i++) ans+=c[i].maxn2;
        }
        else{
            for(int i=1;i<=tot1;i++) ans+=a[i].maxn1;
            for(int i=1;i<=tot2;i++) ans+=b[i].maxn1;
            for(int i=1;i<=tot3;i++) ans+=c[i].maxn1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
