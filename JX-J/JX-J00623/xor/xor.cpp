#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1010];
struct node{
    int l,r;
};

bool cmp(node a,node b){
    return a.l<b.l;
}
node b[500];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long st=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt=0;
            for(int o=i;o<=j;o++){
                cnt^=a[o];
            }
            if(cnt==k){
                st++;
                b[st].l=i;
                b[st].r=j;
            }
        }
    }
    sort(b+1,b+1+st,cmp);
    int ans=1;
    int rr=b[1].r;
    for(int i=2;i<=st;i++){
        if(rr<b[i].l)ans++,rr=b[i].r;
    }cout << ans;
    return 0;
}
