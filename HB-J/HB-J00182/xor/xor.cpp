#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],xor1[500001],sum,r;
vector <int> v[(1<<20)&1];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],xor1[i]=xor1[i-1]^a[i];
    v[0].push_back(0);
    for (int i=1;i<=n;i++){
        if (!v[xor1[i]^m].empty()){
            if (v[xor1[i]^m].back()>=r){
                r=i;
                sum++;
            }
        }
        v[xor1[i]].push_back(i);
    }
    cout<<sum;
    return 0;
}
