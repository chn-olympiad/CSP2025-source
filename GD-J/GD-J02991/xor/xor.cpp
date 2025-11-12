#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[10000000],p[10000000],ans=0;
bool st=false;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0&&n<=2){
		cout<<1;
		return 0;
	}
	int cnt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pls=1;
	for(;pls<=n;){
		st=false;
		for(int j=pls;j<=n;j++){
			if(j==pls){
				cnt=a[j];
			}
			else cnt^=a[j];
			
			if(cnt==k){
				st=true;
				pls=j+1;
				ans++;
				break;
			}
				
		}
		if(st==false){
			pls++;
		}	
	}
	cout<<ans;
	return 0;
	
}
