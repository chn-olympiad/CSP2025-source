#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i])ans++; 
		}
		cout<<ans;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0)ans++;
		}
		for(int i=1;i<=n;i++){
			if(a[i] && a[i+1]){
				ans++;
				i++; 
			}
		}
		cout<<ans;
	}
	return 0;
}
