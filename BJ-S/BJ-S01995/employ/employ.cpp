#include<iostream>
#define LL long long

using namespace std;

const int NR=510;
const int MOD=998244353;

int n,m;
string s;
int c[NR];
bool flag[NR];

LL ans=0;

void dfs(int step,int cnt,int fail){
    if(step>n){
        if(cnt>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[i])continue;
        flag[i]=true;
        if(fail>=c[i]||s[step]=='0')dfs(step+1,cnt,fail+1);
        else dfs(step+1,cnt+1,fail);
        flag[i]=false;
    }  

}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    s=" "+s;

    int count1=0,count0=0;

    for(int i=1;i<=n;i++){
        cin >> c[i];
        if(c[i]==0)count0++;
        if(s[i]=='1')count1++;
    }
    
    if(count1==0){
        cout << 0 << endl;
        return 0;
    }

    dfs(1,0,0);
    cout << ans << endl;
}