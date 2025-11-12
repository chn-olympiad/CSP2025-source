//gitxiaozheng
//rp++!
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,aaa,bbb;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			aaa++;
		}else if(a[i]==0){
			bbb++;
		}
	} 
	if(n<=2&&k==0){
		if(n==1){
			if(a[1]!=0){
				cout<<0;
			}else{
				cout<<1;
			}
		}else{
			cout<<1;
		}
		return 0;
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(aaa+bbb==n){
		if(k==1){
			cout<<aaa;
		}else{
			cout<<bbb;
		}
		return 0;
	}
//	for(int i=2;i<=n;i++){
//		a[i]=(a[i]^a[i-1]);
//	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	int l=0;r=111212;
//	while(l<=r){
//		int mid=(l+r)/2;
//		if(){
//			l=mid;
//		}else{
//			r=mid;
//		}
//	}
//	
 	int t=-114514,ans=0;
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl<<a[i-1]<<endl;
//		cout<<t<<' '<<(1^2)<<' '<<(t^a[i])<<' '<<t<<' '<<a[i]<<'\n';
		if(t==-114514){
			t=a[i];
		}else{
			t=(t^a[i]);
		}
//		cout<<t<<'\n';
		if(t==k||a[i]==k){
			ans++;
			t=-114514;
		}
	}
	cout<<ans;
	return 0;
}
