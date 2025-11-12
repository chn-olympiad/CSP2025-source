#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500010],cnt=0,cnt2=0,cnt3=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			cnt++;
		}else if(a[i]==0){
			cnt2++;
		}else{
			cnt3++;
		}
	}
	if(cnt==n){
		cout<<n/2;
	}else if(cnt3==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]&&a[i]==1){
				ans++;
				i++;
			}else if(a[i]==0){
				ans++;
			}
		}
		if(k==1){
			cout<<cnt;
		}else if(k==0){
			cout<<max(cnt/2,ans);
		}
	}else if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}else if(a[i]==0){
				ans++;
			}
		}
		cout<<ans;
	}else if(k==1){
		cout<<cnt;
	}
	return 0;
}
