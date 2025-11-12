#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll get_a;
char get_c;
bool get_f;
inline ll getint(){
    get_a=0;
    get_c=getchar();
    get_f=0;
    while((get_c<'0'||get_c>'9')&&get_c!=EOF){
        if(get_c=='-'){
            get_f=1;
            get_c=getchar();
            break;
        }
        get_c=getchar();
    }
    while(get_c>='0'&&get_c<='9'){
        get_a=get_a*10+get_c-'0';
        get_c=getchar();
    }
    return get_f?-get_a:get_a;
}

vector<int>a(5005,0);
vector<bool>c(5005,0);

int dfs(int i,int n){
    int mx=0,zo=0,nu=0,ans=0;
    if(i<=n){
        c[i]=0;
        ans+=dfs(i+1,n);
        c[i]=1;
        ans+=dfs(i+1,n);
        c[i]=0;
        ans%=MOD;
    }else{
        for(int j=1;j<=n;j++){
            if(c[j]){
                mx=max(mx,a[j]);
                zo+=a[j];
                nu++;
            }
        }
        if(nu>=3&&zo>(mx<<1)){
            ans=(ans+1)%MOD;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=getint(),ans=0;
    for(int i=1;i<=n;i++)
        a[i]=getint();
    cout<<dfs(1,n)<<'\n';
    return 0;
}

//dont forget remove the gangs!!!

