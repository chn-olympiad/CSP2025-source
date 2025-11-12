#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),he(n+1);
	vector<bool> has(n+1,false);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	he[1]=a[1];
//	for(int i=2;i<=n;i++){
//		he[i]=a[i]^he[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		cout<<he[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			has[i]=true;
		}
	}
	for(int i=1;i<=n;i++){
		int h=a[i];
		for(int j=i+1;j<=n;j++){
			
			if(!has[j]){
				h^=a[j];
				if(a[j]==0) h=0;
			}
			else{
				h=0;
				break;
			}
			if(h==k){
				for(int k=i;k<=j;k++) has[k]=true;
				ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
