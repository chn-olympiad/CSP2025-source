#include <bits/stdc++.h>
using namespace std;
const int mxn=600,mod=998244353;
long long n,m,a[mxn],num=1,tot;
string s;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')tot++;
    }
    stable_sort(a+1,a+n+1,cmp);
    for(int i=tot;i<=n;i++){
        num*=i;
        num%=mod;
    }
    cout<<num;
    return 0;
}
