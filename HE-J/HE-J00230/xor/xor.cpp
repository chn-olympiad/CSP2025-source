#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+2;
int n,k,a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool pda=true;
	bool pdb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			pda=false;
		}
		if(a[i]!=1 && a[i]!=0){
			pdb=false;
		}
	}
	if(k==0 && pda){   //te shu A xing zhi
		cout<<n/2<<endl;
		return 0;
	}
	int ans=0;
	if(k==1 && pdb){   //te shu B xing zhi
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(k==0 && pdb){   //te shu B xing zhi
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
		int cnt1=0;
		for(int i=1;i<=n;i+=2){
			if(a[i-1]==a[i] && a[i]==1){
				cnt1++;
			}
		}
		cout<<ans+cnt1<<endl;
		return 0;
	}
	return 0;
}
