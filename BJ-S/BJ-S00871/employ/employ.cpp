#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const long long idx=998244353;
int n,m,c[N];
string s;
bool check(vector<int> p){
    int cnt=0,po=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt++;
        else if(c[p[i]] <= cnt)cnt++;
        else po++;
    }
    return po>=m;
}
int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    vector<int> p(n);
    for(int i=0;i<n;i++)p[i]=i+1;
    long long ans=0;
    do{
        if(check(p))ans++;
        ans%=idx;
    }while(next_permutation(p.begin(),p.end()));
    printf("%lld\n",ans%idx);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
