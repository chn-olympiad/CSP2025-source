#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int bgkl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1){
			bgkl=1;
		}
	}
	if(k==0&&bgkl==0){
		cout<<n/2<<"\n";
		return 0;
	}
	if(k==1){
		int t=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				t++;
			}
		}
		cout<<t<<"\n";
		return 0;
	}
	int l=1,ans=0,flag=0;
	while(l<n){
		if(a[l]==k){
			l++;
			ans++;
		}
		for(int i=l;i<=n;i++){
			if((sum[i]^sum[l-1])==k){
				l=i;
				ans++;
				flag=1;
				break;
			}
		}
		flag=0;
		if(flag==0){
			l++;
			if(l>n){
				break;
			}
			for(int i=l;i<=n;i++){
				if((sum[i]^sum[l-1])==k){
					l=i;
					ans++;
					flag=1;
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
