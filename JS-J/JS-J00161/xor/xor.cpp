#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}g[500100];
bool cmp(node a,node b){
    return a.r<b.r;
}
map<int,int>m;
int n,k,a[500100],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    m[0]=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res^=a[i];
        //cout<<res<<' ';
        int temp=res^k;
        if(m[temp]!=0){
            //cout<<endl<<endl<<temp<<' '<<m[temp]<<endl<<endl;
            cnt++;
            g[cnt].l=m[temp];
            g[cnt].r=i;
            m[temp]=0;
        }
        m[res]=i+1;
    }
//    for(int i=0;i<4;i++){
//        cout<<m[i]<<endl;
//    }
    sort(g+1,g+1+cnt,cmp);
//    for(int i=1;i<=cnt;i++){
//        cout<<g[i].l<<' '<<g[i].r<<endl;
//    }
    int ans=0,last=0;
    for(int i=1;i<=cnt;i++){
        if(g[i].l>last) {
            ans++;
            last=g[i].r;
        }
    }
    cout<<ans;
    return 0;
}
