#include"bits/stdc++.h"
#define mod 998244353
using namespace std;
struct node{
    int x,id;
    bool operator<(const node &xx) const {
        return id<xx.id;
	}
};
node a[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].id=i;
    }
    int ans=0;
    while(1){
        int tmp=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i].x<=tmp||s[i-1]=='0')
                tmp++;
            else
                cnt++;
        }
        if(cnt>=m)
            ans++;
        if(ans>=mod)
            ans-=mod;
        if(!next_permutation(a+1,a+n+1))
            break;
    }
    printf("%d\n",ans);
}
