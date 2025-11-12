#include<bits/stdc++.h>
using namespace std;
struct st{
    int l;
    int r;
}a[1050];
int g[1050];
int lp[1050];
int q[1050];
int t[1050];
int h,c;
int n,k;
int mx,rmx;
int f[1050];
bool cmp(st u,st v){
    return u.l<v.l;
}
void dfs(int u,int s){
    mx=max(mx,s);
    //cout<<u<<" ";
    int d=u+1;
    int I;
    if(d>rmx){
        c=-1;
    }
    for(int i=1;i<=h+1;i++){
        if(i==h+1)c=-1;
        if(a[i].l>=d){
            I=i;
            break;
        }
    }
    //cout<<I;
    mx=max(mx,s);
    for(int i=I;i<=h;i++){
        dfs(a[i].r,s+1);
        if(c==-1)return;
    }
    mx=max(mx,s);
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int p=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        p^=x;
        f[i]=p;
        //cout<<f[i]<<" ";

    }

    //cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            int x=f[i];
            int y=f[j];
            int o=x^y;
            //cout<<o<<endl;
            if(o==k){
                if(g[i]==0){
                    h++;
                    g[i]=1;
                    a[h].l=j+1;
                    a[h].r=i;
                }break;
            }
        }
    }
    sort(a+1,a+h+1,cmp);

    for(int i=1;i<=h;i++){
        rmx=max(rmx,a[i].r);
    }



    /*for(int i=1;i<=h;i++){
        lp[a[i].l]=i;
        for(int j=a[i].l;j>=1;j--){
            if(lp[j]==0)lp[j]=i;
            else break;
        }
    }*/
    for(int i=1;i<=h;i++){
        dfs(a[i].r,1);
        sa:
            ;
    }
    cout<<mx;
    return 0;
}
