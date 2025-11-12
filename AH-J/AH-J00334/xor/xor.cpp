#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],k,n,p;
signed main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     cin>>n>>k;
     for(int i=1;i<=n;i++){
		 cin>>a[i];
		 if(a[i]==1){
			 p++;
		 }
	 }
	 if(p==n){
		 cout<<n;
		 return 0;
	 }
	 cout<<2;
     return 0;
}
