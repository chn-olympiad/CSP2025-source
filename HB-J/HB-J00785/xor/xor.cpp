#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],ans,ans0,ans1;
bool fl=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1&&fl) fl=0;
		if(a[i]==0) ans0++;
		else if(a[i]==1) ans1++;
	}
	
	if(fl){ /*A&B_pts*/
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]!=0&&a[i]==a[i+1]){
					ans0++;
				}
			}
			cout<<ans0;
		}else if(k==1){
			cout<<ans1;
		}
	}else{ /*Lucky_pts*/
		int now=0;
		for(int i=1;i<=n;i++){
			now=now xor a[i]; /*??*/
			if(now==k){
				ans++;
				now=0;
			}
		}
		cout<<ans;
	}
	/* :( */
	
	return 0;
}
