#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
			
		}
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1){
				s++;
				if(s>0&&s%2==0){
					s=0;
					ans++;
				}
				
			}
			else s=0;
		}
	
		
	}
	cout<<ans;
	return 0;
}