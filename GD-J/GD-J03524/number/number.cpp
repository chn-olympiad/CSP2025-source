#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
char a[N],b[N];
int main(){
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>a,n=strlen(a);
    for(int i=0;i<n;i++) if(a[i]>='0'&&a[i]<='9') b[m++]=a[i];
    sort(b,b+m);
    for(int i=m-1;i>=0;i--) cout<<b[i];
    return 0;
}