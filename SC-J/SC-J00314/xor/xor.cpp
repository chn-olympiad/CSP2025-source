#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],a_max,a_min=0x3f3f3f3f,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a_max=max(a_max,a[i]);
		a_min=min(a_min,a[i]);
	}
	if(a_max==a_min&&a_max==1){
		if(k==0){
			cout<<n/2;
			return 0;
		}else if(k==1){
			cout<<n;
			return 0;
		}
	}else if(a_max==1&&a_min==0){
		if(k==1){
			for(int i=1;i<=n;i++){
				int tmp=i+1;
				if(a[i]==a[tmp]){
					if(a[i]==1)
						ans++;
					continue;
				}else if(a[i]!=a[tmp]){
					ans++;
					i++;
					continue;
				}
			}
			cout<<ans;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;i+=2){
				ans++;
			}
			cout<<ans;
			return 0;
		}
		
	}
	
}