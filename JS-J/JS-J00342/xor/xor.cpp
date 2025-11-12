#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN=5e5+8;
const int MAXA=2e6+8;
ifstream fin("xor.in");
ofstream fout("xor.out");
int n,k,a[MAXN],mp[MAXA],sum,ans,lst;
int main(){
    fin>>n>>k;
    for(int i=1;i<=n;i++){
        fin>>a[i];
        mp[sum]=i;
        sum^=a[i];
        int x=sum^k;
        if(mp[x]!=0&&mp[x]>lst)ans++,lst=i;
    }fout<<ans;
}
