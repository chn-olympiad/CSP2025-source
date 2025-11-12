#include<bits/stdc++.h>
using namespace std;
int n,k,a[20005],x=0,b[20005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) x++;
	}
	if(k==0&&x==n){
		cout<<n/2;
	}
	else if(k<=1){
		if(k==1) cout<<x;
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i!=n&&a[i]==1&&a[i+1]==1&&b[i]==0&&b[i+1]==0) ans++,b[i]=1,b[i+1]=1;
				if(a[i]==0) ans++;
			}
			cout<<ans;
		}
	}
	else{
		int ans=0,cnt=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]==k){
				ans++;
				cnt=0;
			}
			cnt|=a[i];
			if(cnt==k) ans++;
		}
		cout<<ans;
	}
	return 0;
}
