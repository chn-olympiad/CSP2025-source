#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

int n,k,a[maxn];

vector<int> bi[(1<<20)];
int lst[(1<<20)];

void solve1(){
    int cnt=0,pre=0;
    for (int i=1;i<=n;i++){
        while (bi[a[i]^k].size() && bi[a[i]^k][lst[a[i]^k]]<=pre-1) lst[a[i]^k]++;
        if (bi[a[i]^k].size() && bi[a[i]^k][lst[a[i]^k]]<i){
            cnt++;
            pre=i;
        }
    }

    cout<<cnt;
}

void solve(){
    int pre=0,cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=pre;j<i;j++){
            if ((a[i]^a[j])==k){
                //cout<<i+1<<" "<<j<<endl;
                cnt++;
                pre=i;
            }
        }
    }
    cout<<cnt;
}

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    bi[0].push_back(0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]^a[i-1];
        bi[a[i]].push_back(i);
    }

    if (n<=5000) solve();
    else solve1();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
