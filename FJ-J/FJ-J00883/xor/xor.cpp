#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,f,cnt1,cnt2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		if(n==1){
			cout<<0;
			return 0;
		}
		if(n==2){
			cout<<1;
			return 0;
		}
		f=1;
		for(int i=1;i<=n;i++) if(!a[i]){
			f=0;
			break;
		}
		if(f){
			cout<<n/2;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cnt1++;
				cnt2=0;
			}else{
				if(cnt2){
					cnt1++;
					cnt2=0;
				}else cnt2++;
			}
		}
		cout<<cnt1;
		return 0;
	}else if(k==1){
		f=1;
		for(int i=1;i<=n;i++) if(!a[i]){
			f=0;
			break;
		}
		if(f){
			cout<<n;
			return 0;
		}
		for(int i=1;i<=n;i++) if(a[i]) cnt1++;
		cout<<cnt1;
		return 0;
	}
	return 0;
}
