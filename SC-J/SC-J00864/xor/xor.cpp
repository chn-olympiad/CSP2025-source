#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,x,ans;
int a[2000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;n>=i;i++){
		scanf("%d",&a[i]);	
		if(a[i]==k) ans++;
	}	
	if(ans==0)
		ans=n/2;
	cout<<ans;	 
	return 0; 
} 