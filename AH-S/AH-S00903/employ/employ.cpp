#include <bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
int jia(int A,int B){return A+B<mod?A+B:A+B-mod;}
int jin(int A,int B){return A-B<0?A-B+mod:A-B;}
int n,m,s[N+5],c[N+5];
string str;
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> str; str=' '+str;
    for(int i=1;i<=n;++i) s[i]=(str[i]=='1');
    for(int i=1;i<=n;++i) cin >> c[i];
    vector<int> p(n);
    for(int i=0;i<n;++i) p[i]=i+1;
    int ans=0;
    do{
        int qu=0,res=0;
        for(int i=1;i<=n;++i){
            if(!s[i] || qu>=c[p[i-1]]) ++qu;
            else ++res;
            if(res==m){
                ++ans;
                break;
            }
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << ans%mod << '\n';
    return 0;
}