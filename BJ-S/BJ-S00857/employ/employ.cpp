#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;

int qpow(int a,int b){
    if(b==1){
        return a;
    }

    if(b==0){
        return 1;
    }

    int x; x=qpow(a,b/2);
    if(b&1){
        return x*x%mod*a%mod;
    }
    else{
        return x*x%mod;
    }
}

int n,m;
string s;
int x[20];
int a[20];
int b[20];
int ans;
void dfs(int now){
    if(now==n){
        int die; die=0;

        for(int i=1;i<=n;i++){
            if(die>=x[a[i]] || s[i-1]=='0'){
                die++;
            }
        }

        if(n-die>=m){
            ans++;
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(!b[i]){
            a[now+1]=i;
            b[i]=1;
            dfs(now+1);
            a[now+1]=0;
            b[i]=0;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    dfs(0);
    cout<<ans<<endl;
    return 0;
}

/*
Take me to where you are, won't you?
Till then, I'm struggling.
Curse of justice, you don't know.
*/
