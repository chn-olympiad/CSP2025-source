#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],d[N],p[N][N],g[N][N];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
    g[i][i]=a[i];
    p[i][i]=(a[i]==k);
    for(int j=i+1;j<=n;j++){
        g[i][j]=(g[i][j-1]^a[i]);
        p[i][j]=(g[i][j]==k);
    }
}
for(int i=1;i<=n;i++){
    d[i]=d[i-1]+p[i][i];
    for(int j=1;j<=i;j++){
        d[i]=max(d[i],d[j]+p[i][j]);
    }
}
cout<<d[n];
 return 0;
}
