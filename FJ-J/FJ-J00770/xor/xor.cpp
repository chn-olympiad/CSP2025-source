#include<bits/stdc++.h>
using namespace std;
int a[1145140],r,n,k,ans,maxn;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		ans=0;
		for(int i=k;i<=n;i++){
			int x=a[i];
			if(a[i]==k){
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++){
				x=(x^a[j]);
				if(x==k){
					ans++;
					i=j;
					break;
				}
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
