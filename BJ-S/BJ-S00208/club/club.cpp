#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cnt[5],d[10],jishu=0;
struct Node{int aa[5],id1,id2,id,cha;}a[500];
bool cmp(Node x,Node y){
    return x.cha>y.cha;
}
int solve(){
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        int z=a[i].id1;int c=a[i].id2;
        ++cnt[z];
        if(cnt[z]<=n/2) {ans+=a[i].aa[z];}
        else {ans+=a[i].aa[c];}
    }
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i].id=i;
            cin>>a[i].aa[1]>>a[i].aa[2]>>a[i].aa[3];
            if(a[i].aa[1]>=a[i].aa[2]&&a[i].aa[2]>=a[i].aa[3]){a[i].id1=1;a[i].id2=2;}
            else if(a[i].aa[1]>=a[i].aa[3]&&a[i].aa[3]>=a[i].aa[2]){a[i].id1=1;a[i].id2=3;}
            else if(a[i].aa[2]>=a[i].aa[1]&&a[i].aa[1]>=a[i].aa[3]){a[i].id1=2;a[i].id2=1;}
            else if(a[i].aa[2]>=a[i].aa[3]&&a[i].aa[3]>=a[i].aa[1]){a[i].id1=2;a[i].id2=3;}
            else if(a[i].aa[3]>=a[i].aa[1]&&a[i].aa[1]>=a[i].aa[2]){a[i].id1=3;a[i].id2=1;}
            else if(a[i].aa[3]>=a[i].aa[2]&&a[i].aa[2]>=a[i].aa[1]){a[i].id1=3;a[i].id2=2;}
            a[i].cha=a[i].aa[a[i].id1]-a[i].aa[a[i].id2];
        }
        cout<<solve()<<endl;
        for(int i=1;i<=3;i++) cnt[i]=0;
        ans=0;
    }
    return 0;
}