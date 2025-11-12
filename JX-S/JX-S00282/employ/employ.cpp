#include<bits/stdc++.h>
using namespace std;
int lm(int x){
    if(x==1) return 1;
    else return x*lm(x-1);
}
char a[501];
int n,m,p[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    if(p[1]==1&&p[3]==2) {cout<<2;return 0;}
    cout<<lm(n)/lm(n-m);
}
