#include<bits/stdc++.h>
using namespace std;
bool c[100010][25];
bool bk[25],bt[25];
int n,k,bkn,btn,cn[100010];
int zz=0;
struct llrr{
    int l,r;
}a[100010];
void ad(int x,int i){
    string s;
    while(x){
        c[i][++cn[i]]=bool(x&1);
        x>>=1;
    }
}
void btad(int j){
    btn=max(btn,cn[j]);
    for(int i=1;i<=btn;i++){
        bool x=bt[i],y=c[j][i];
        if(x==y) bt[i]=0;
        else bt[i]=1;
    }
}
void btja(int j){
    btn=max(btn,cn[j]);
    for(int i=1;i<=btn;i++){
        bool x=bt[i],y=c[j][i];
        if(x==y) bt[i]=0;
        else bt[i]=1;
    }
}
bool pd(){
    for(int i=1;i<=max(bkn,btn);i++){
        if(bk[i]!=bt[i]) return 0;
    }
    return 1;
}
bool cmp(llrr x,llrr y){
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
int dfsb=0;
void dfs(int t,int l,int r){
 //   cout<<t<<" ";
    if(l>zz){
        dfsb=max(dfsb,t);
        return ;
    }
    for(int i=l;i<=zz;i++){
        if(a[i].l>r){
            dfs(t+1,i+1,a[i].r);
            return ;
        }
    }
    dfs(t,zz+1,r);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int z0=0,z1=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>=2) z0=1;
        if(x==1) z1++;
        ad(x,i);
    }
    int tk=k;
    while(k){
        bk[++bkn]=bool(k&1);
        k>>=1;
    }
        /*
    n=3;
    btad(1);
    for(int i=1,e=0,j=1;i<=n;){
        if(pd()==1){
            e=1;
            cout<<i<<" "<<j<<endl;
            if(i==n) break;
        }
        if(e==1||j==n){
            if(i==j){
                e=0;
                j++;
                btad(j);
                continue;
            }
            btja(i);
            i++;
            continue;
        }
        if(pd()==0){
            j++;
            btad(j);
        }
    }
    */
    /*
    for(int ek=4,n=1;n<=4;n++){
        memset(bt,0,sizeof(21));
        btn=0;
        btad(1);
        for(int i=1,e=0,j=1;i<=n;){
            if(pd()==1){
                e=1;
                cout<<i<<" "<<j<<endl;
                if(i==n) break;
            }
            if(e==1||j==n){
                if(i==j){
                    e=0;
                    j++;
                    btad(j);
                    continue;
                }
                btja(i);
                i++;
                continue;
            }
            if(pd()==0){
                j++;
                btad(j);
            }
        }
    }
    */
    for(int i=1;i<=n;i++){
        memset(bt,0,sizeof(21));
        btn=0;
        for(int j=i;j<=n;j++){
            btad(j);
            if(pd()==1){
                a[++zz]={i,j};
  //              cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
    sort(a+1,a+zz+1,cmp);
    dfs(0,1,0);
    cout<<dfsb;
    return 0;
}
