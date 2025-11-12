#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int n,k;
int a[MAXN];
bool flag1[MAXN],flag2[MAXN];
vector<vector<int> > q;
int quanzhi(int l,int r){
    int ans = a[l];
    for(int i = l+1;i <= r;i++){
        ans = ans^a[i];
    }
    return ans;
}

int main(){
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^nihao.zhe ti shi ren.FUCKYOUFUCKYOU!!!chu ti ren dhi ri ben tian huang
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vector<int> tmp;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            tmp.push_back(quanzhi(i,j));
        }
        q.push_back(tmp);
        tmp.clear();
    }
    int cnt = 0;
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(q[i][j] == k && !flag1[i] && !flag2[k]) cnt++;
            }
    }
    cout<<cnt;
    return 0;
}
