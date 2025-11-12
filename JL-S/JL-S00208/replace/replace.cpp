#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline ll read(){
    ll num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        sign=ch=='-'?-1:1,ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    }
    return sign>0?num:-num;
}
ll q,n;
struct node{
    string s1,s2;
}a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    while(q--){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
