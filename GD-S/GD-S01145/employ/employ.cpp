#include<bits/stdc++.h>
using namespace std;
struct RP{
    int id,v;
    friend bool operator<(RP x,RP y){return x.id<y.id;}
}t[20];
int n,m,a[505],C[505][505];
long long sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    if(n<=20){
        for(int i=1;i<=n;++i){
            cin>>t[i].v;
            t[i].id=i;
        }
        sort(t+1,t+1+n);
        long long sum=0;
        do{
            int u=0,c=0;
            for(int i=1;i<=n;++i){
                if(t[i].v<=c||s[i-1]=='0'){
                    c++;
                    continue;
                }else u++;
            }
            if(u>=m)sum++;
        }while(next_permutation(t+1,t+1+n));
        cout<<sum%998244353;
        return 0;
    }
    if(n==m){
        for(auto i:s)if(i!='1'){
            cout<<0;
            return 0;
        }
        cout<<1;
        return 0;
    }
    const int Mod=998244353;
    int l=0;
    for(int i=1,o;i<=n;++i)cin>>o,l+=(o==0);
	n-=l;
    for(int i=1;i<=n+1;++i)C[i][i]=C[i][1]=1;
    for(int i=1;i<=n+1;++i)for(int j=2;j<i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    for(int i=m;i<=n;++i)sum=(sum+C[n+1][i+1])%Mod;
    cout<<sum;
    return 0;
}
