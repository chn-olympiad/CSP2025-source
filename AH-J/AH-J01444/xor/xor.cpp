#include<bits/stdc++.h>
using namespace std;
int n,k,ans,cnt;
int a[500010],vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			sum^=a[j];
			if(sum==k){
			ans++;
			}
		}
		sum=0;
	}	
	if(k==0){
	cout<<ans-cnt;
	}else{
	cout<<ans;		
	}
	return 0;
}
