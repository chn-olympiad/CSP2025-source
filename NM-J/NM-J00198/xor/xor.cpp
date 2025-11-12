#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k;
int a[N];
int s=INT_MAX;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=min(s,a[i]);
	}
	if(k==0&&s==1)cout<<n/2;
	else if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else{
				if(a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}else if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
