#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,m,i,j1=0;
cin>>n>>m;
for(i=1;i<=n;i++){
cin>>a[i];
	if(m==a[i]){
	j1++;
	}
}
cout<<j1;
return 0;
}
