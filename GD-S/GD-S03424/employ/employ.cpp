#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char a[maxn],c[maxn];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++) cin>>a[i];
	for(int i = 0;i<n;i++) cin>>c[i];
	 long long ans = 1;
	 int sum = n;
	 for(int i = 0;i<n;i++){
	 	if(c[i] == 0) sum-=1;
	 }
	 for(int i = 1;i<=sum;i++){
	 	for(int j = 1;j<=m;j++){
	 		ans = ans*i;
	 		ans = ans/j;
		 }
	 }
	 cout<<ans<<"\n"; 
} 
