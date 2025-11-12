#include<bits/stdc++.h>
using namespace std;
int a[130000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int cnt=0;
			if(j-i+1>m){
				for(int k=i;k<=j;k++){
					cnt^=a[k];
				}
				ans=max(ans,cnt);
			}
		}
	}
	cout<<ans;
	return 0;
}
