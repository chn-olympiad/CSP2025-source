#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=510;
const int Mod=998244353;

int n,m;
string s;
int a[N],d[N];
bool flag[N];
int ans;

void dfs(int k) {
    if(k>n) {
        int cnt_no=0,cnt_yes=0;
        for(int i=1;i<=n;i++) {
            if(cnt_no>=a[d[i]]) cnt_no++;
            else {
                if(s[i]=='1') cnt_yes++;
                else cnt_no++;
            }
        }
        if(cnt_yes>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!flag[i]) {
            flag[i]=1,d[k]=i;
            dfs(k+1);
            flag[i]=0;
        }
    }
}

void work1() { //n<=18
    dfs(1);
    cout<<ans;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=18) work1();
    else cout<<0;
}