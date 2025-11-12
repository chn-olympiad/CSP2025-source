#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a n ans;
struct ab{
    int a b c;
}a[200005];
void dfs(int x cnt ca cb cc){
    ans=max(ans,cnt);
    if(x==n) return;
    if(ca+1<=n/2) dfs(x+1,cnt+a[x+1],a[x+1])
}

int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    return 0;
}
