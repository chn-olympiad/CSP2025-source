#include<bits/stdc++.h>
using namespace std;
int n,k,a[555555],ans,pre;
char cheA=1,cheB=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) cheA=0;
		if(a[i]>1) cheB=0;
	}
	if(cheA){
		cout<<n/2;
	}
	else if(cheB){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
				if(a[i]==0) cnt0++;
				else cnt1++;
			}
		if(k==0) cout<<cnt0+cnt1/2;
		else cout<<cnt0/2+cnt1;
	}
	else{
		for(int i=2;i<=n;i++){
			pre^=a[i];
			if(pre==k){
				ans++;
				pre=0;
			}
		}
		cout<<ans;
	}
	return 0;
}
