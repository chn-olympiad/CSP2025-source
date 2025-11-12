#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[500005],cnt=0,ans,xo[500005];
struct node{
    int l,r;
}qj[500005];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xo[i]=(xo[i-1]^a[i]);
        for(int j=1;j<=i;j++){
            if((xo[i]^xo[j-1])==k){
                qj[++cnt].l=j,qj[cnt].r=i;
            }
        }
    }/*
    for(int i=1;i<=cnt;i++){
        cout<<qj[i].l<<" "<<qj[i].r<<endl;
    }*/
    sort(qj+1,qj+cnt+1,cmp);
    int ans=1,l1=qj[1].l,r1=qj[1].r;
    for(int i=2;i<=cnt;i++){
        if(qj[i].l>r1){
            r1=qj[i].r;
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
