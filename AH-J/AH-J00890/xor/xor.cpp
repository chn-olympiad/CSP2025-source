#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			continue;
		}
		int h=a[i];
		for(int j=i+1;j<n;j++){
			h=h^a[j];
			if(h==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
