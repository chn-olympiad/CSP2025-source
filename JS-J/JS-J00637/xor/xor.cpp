//095833
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+5;
int n,k;
int a[maxn];
int qzh[maxn];
struct node{
    int l;
    int r;
};
struct node s[maxn];
int cnt;
int tot=-maxn;
void dfs(int pos,int value){
    tot=max(tot,value);
    if(value+cnt-pos<tot)
        return;
    for(int i=pos;i<=cnt;i++){
        if(value+cnt-i<tot)
            break;
        if(s[i].l>s[pos].r){
            dfs(i,value+1);
        }
    }
    return ;
}
signed main(){
    //jiashangtepan
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int type=true;
    int tic=true;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
                tic=false;
        if(a[i]!=1&&a[i]!=0)
            type=false;
    }
    if(tic){
        if(k>1){
            cout<<"0";
        }
        if(k==1){
            cout<<n;
        }
        if(k==0){
            cout<<n-1;
        }
        cout<<endl;
        return 0;
    }
    else if(type){
        if(k>1){
            cout<<0;
        }
        if(k==1){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)
                    sum++;
            }
            cout<<sum;
        }
        if(k==0){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)
                    sum++;
            }
            for(int i=1;i<=n;i++){
                if(a[i]==1&&a[i-1]==1){
                    sum++;
                    a[i]=0,a[i-1]=0;//a[i-1] ke you ke wu
                }
            }
            cout<<sum;
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        qzh[i]=(qzh[i-1]^a[i]);
    }
    //int p,q;//left pointer right pointer
    for(int p=1;p<=n;p++){
        for(int q=p;q<=n;q++){
            int w;
            w=(qzh[q]^qzh[p-1]);
            if(w==k){
                //struct node temp;
                //temp.l=p;
                //temp.r=q;
                ++cnt;
                s[cnt].l=p;
                s[cnt].r=q;
                break;//if we have [i,j] ; [i,j+k] is uneccessary
            }
        }
    }
    //sort(s+1,s+cnt-1,cmp);
    //natural consequence
    //smaller one eliminate bigger one
    for(int i=1;i<=cnt;i++){
        if(cnt-i+1<tot)
            break;
        dfs(i,1);
    }
    cout<<tot<<endl;
    return 0;
}
