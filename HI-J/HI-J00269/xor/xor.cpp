#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int a[N],to[M],n,k,len=0;
struct stu{
    int l,r;
    bool operator<(stu &b){
        return r<b.r;
    }
};
stu s[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(to,-1,sizeof to);
    cin >> n >> k;
    a[0]=0;
    to[0]=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]^=a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(to[a[i]^k]!=-1){
            ++len;
            s[len].l=to[a[i]^k]+1;
            s[len].r=i;
        }
        to[a[i]]=i;
    }
    sort(s+1,s+len+1);
    int t=0,ans=0;
    for(int i=1;i<=len;i++){
        if(s[i].l>t){
            ++ans;
            t=s[i].r;
        }
    }
    cout << ans;
    return 0;
}
