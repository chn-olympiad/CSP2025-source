#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e5+5;
ll a [maxn];
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n,a[120],b[20][20];
for(int i=1;i<=m*n;i++){
	cin>>a[i];
}
int c=a[1];
if(m==1&&n==1){
	cout<<1<<" "<<1;
}

return 0;
}
