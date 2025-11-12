#include<bits/stdc++.h>

using namespace std;
int n,k;
int a[500005],xsum[500005];
struct node{
    int l,r;
};
vector<node> b;
bool cmp(node x,node y){
    //if(x.r!=y.r){
        return x.r<y.r;
    //}
    //return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xsum[i]=(a[i]^xsum[i-1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((xsum[j]^xsum[i-1])==k){
                b.push_back({i,j});
            }
        }
    }
    //for(node x:b){
    //    cout<<x.l<<" "<<x.r<<endl;
    //}
    sort(b.begin(),b.end(),cmp);
    int r=0,cnt=0;
    for(int i=0;i<b.size();i++){
        if(r<b[i].l){
            cnt++;
            r=b[i].r;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
