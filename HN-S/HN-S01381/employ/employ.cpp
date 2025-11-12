#include<bits/stdc++.h>
using namespace std;
const int N=510;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int n,m;
char s[N];
int c[N],a[N];

int main(){
    //状压 dp[i][j] 表示考虑到第 i 天，集合使用情况是 k，j 个人没有被录取的方案
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)a[i]=i;
    int ans=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=c[a[i]])cnt++;
            else if(s[i]=='0')cnt++;
        }
        // cout<<"cnt="<<cnt<<'\n';
        if(cnt<=n-m)ans++;
    }while(next_permutation(a+1,a+1+n));
    cout<<ans;
    return 0;
}