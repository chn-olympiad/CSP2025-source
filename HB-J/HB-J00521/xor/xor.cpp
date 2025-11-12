#include <bits/stdc++.h>
using namespace std;
#define el '\n'
const int N=5e5+10;
int n,k;
int a[N];
int ans;
struct word{
    int x,y;
};
vector<word> len;
bool check(int l,int r){
    int res=a[l];
    for(int i=l+1;i<=r;i++) res^=a[i];
    return res==k;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if(check(l,r)){
                ans++;
                len.push_back({l,r});
            }
        }
    }
    cout << ans;
    return 0;
}
