#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+10;
int n,k;
int a[N];
int sum[N];
ll ans;
struct node{
    int l,r;
};
vector<node>qu;
bool cmp(node x,node y){
    if(x.r!=y.r){
        return x.r<y.r;
    }
    else return x.l>y.l;
}
int main(){
    IOS;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }

    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            int x=sum[j]^sum[i-1];
            if(x==k){
                qu.push_back({i,j});
            }
        }
    }

    if(qu.size()==0){
        cout<<0;
        return 0;
    }

    sort(qu.begin(),qu.end(),cmp);

    int r1=qu[0].r;
    int si=qu.size()-1;
    ans++;
    for(int i=1;i<=si;i++){
        if(r1<qu[i].l) {
            ans++;
            r1=qu[i].r;
        }
    }
    cout<<ans;
    return 0;
}

/*
4 3
2 1 0 3


*/













