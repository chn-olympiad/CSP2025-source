#include <bits/stdc++.h>
using namespace std;
int n,m,res;
int k[11]={1,1,1,1,1,1,1,1,1,1,1};
string s;
int pat[505];
int solve(int ceng,int k,int h[11],int ac){
    if (ceng>n){
        if (ac>=m) res++;
        return 0;
    }
    int buf[11];
    for (int i=0;i<n;i++) buf[i]=h[i];
    for (int i=0;i<n;i++){
        if (h[i] && i!=k){
            buf[i]=0;
            solve(ceng+1,i,buf,ac+((ceng-ac-1<pat[i]) && (s[ceng-1]=='1')));
            buf[i]=1;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for (int i=0;i<=n;i++) cin>>pat[i];
    solve(1,-1,k,0);
    cout<<res;
}
