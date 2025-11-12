#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1000;
int n,m,s[N];
bool cmp(int a,int b) {
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>s[i];
    int l=n*m;
    int to=s[1];
    sort(s+1,s+1+l,cmp);
    int st=-1;
    for (int i=1;i<=l;i++) {
        if (s[i]==to) {
            st=i;
            break;
        }
    }
    int h=(st+n-1)/n;
    cout<<h<<" ";
    if (h%2==1) cout<<st-(h-1)*n;
    else cout<<n-(st-(h-1)*n)+1;
    return 0;
}