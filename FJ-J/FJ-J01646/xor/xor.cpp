#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int ans;
int sum;
int cnt;
bool p=true; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		if(a[i]!=1&&a[i]!=0) p=false;
	}
	if(k==0&&cnt==n){
		cout<<n/2;
		return 0;
	}else if(k==1&&p){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}else{
			sum=0;
			for(;i<=n;i++){
				sum=sum^a[i];
				if(sum==k){
					ans++;
					break;
				}
				if(a[i]==k){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
