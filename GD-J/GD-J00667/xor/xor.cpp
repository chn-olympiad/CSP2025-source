#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int maxa=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	int maxn=0;
	if(k==0){
		for(int i=0;i<n;i++){
			int ans=0;
			for(int j=i;j<n;j++){
				if(a[j]==0)ans++;
				else if(a[j]==a[j+1]){
					ans++;
					j++;
				}
			}
			maxn=max(maxn,ans);
		}
	}
	if(k==1){
		for(int i=0;i<n;i++){
			int ans=0;
			for(int j=i;j<n;j++){
				if(a[j]==1)ans++;
				else if(a[j]!=a[j+1]){
					ans++;
					j++;
				}
			}
			maxn=max(maxn,ans);
		}
	}
	cout<<maxn;
	return 0;
}
