#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i])ans++;
		}
		cout<<ans;
	}
	else if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]&&a[i+1]){
				i++;
				ans++;
			}
			else if(!a[i])ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==k)ans++;
		}
		cout<<ans;
	}
	return 0;
}
