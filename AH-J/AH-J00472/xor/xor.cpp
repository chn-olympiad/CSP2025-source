#include<bits/stdc++.h>
using namespace std;
int n,k,x;
int g[500005][27];
int s[27];
int ans;
void work(int x,int p){
    int l=23;
    while(x){
        g[p][l]=x%2;
        x/=2;
        l--;
    }
}
struct node{
    int l,r;
    bool operator<(const node &b){
        return r<b.r;
    }
}a[500005];
int cnt;
bool panji(int l,int r){
    for(int i=1;i<=23;i++){
        if((g[r][i]-g[l-1][i]+2)%2!=s[i]%2)return false;
    }
    return true;
}
int Arsenal(int p){
    int q=1,sum=0,jb=23;
    while(jb){
        sum+=g[p][jb]*q;
        q*=2;
        jb--;
    }
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        work(x,i);
    }
    int l=23;
    while(k){
        s[l]=k%2;
        k/=2;
        l--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=23;j++){
            g[i][j]+=g[i-1][j];
            g[i][j]%=2;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(panji(i,j)){
                a[++cnt].l=i;
                a[cnt].r=j;
            }
        }
    }
    sort(a+1,a+1+cnt);
    ans=1;
    int right=a[1].r;
    for(int i=2;i<=cnt;i++){
        if(right<a[i].l){
            ans++;
            right=a[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}
