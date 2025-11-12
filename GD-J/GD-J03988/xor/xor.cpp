#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll k;
ll a[500010],b[500010];
ll ans=0;
vector<pair<int,int>> p;

bool check(int l,int r){
    for(auto t:p){
        int s=t.first,z=t.second;
        if((l<=s&&s<=r)||(l<=z&&z<=r))return 0;
    }
    return 1;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %lld",&n,&k);
    b[0]=0;
    for(int i=1;i<=n;i++){scanf("%lld",&a[i]);b[i]=b[i-1] xor a[i];}
    for(int r=1;r<=n;r++){
        for(int l=1;l<=r;l++){
            if((b[r]xor b[l-1])==k){
                if(check(l,r)){ans++;p.push_back({l,r});}
            }
        }
    }
    printf("%lld",ans);
    return 0;
}