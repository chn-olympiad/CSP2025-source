#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * le6;
int k,n;
vector<int> a(n);
vector<int> cnt(MAXN, 0);
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>k>>n;
    for(int i=0;i<n; ++i){
        cin>>a[i];
        cnt[a[i]]++;

    }

    return 0;
}
