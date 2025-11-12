#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
#define ll long long
ll n,k,a[N],h[N][N],t;
struct stu{
    int s,e;
};
stu p[N*N];
bool cmp(stu a,stu b){
    if(a.e==b.e)return a.s>b.s;
    return a.e<b.e;

}
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<h[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        h[i][i]=a[i];
        if(h[i][i]==k)p[++t]={i,i};
        for(int j=1;j<i;j++){
            h[j][i]=h[j][i-1]^a[i];
            if(h[j][i]==k)p[++t]={j,i};
        }
    }
    //pr();
    sort(p+1,p+1+t,cmp);
    int ans=0,ee=0;
    for(int i=1;i<=t;i++){
        if(p[i].s>ee){
            ee=p[i].e;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
