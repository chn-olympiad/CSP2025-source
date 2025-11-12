#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int maxx=-2e9;
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(cnt==n){
		cout<<k;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int h=0;
			for(int k=i;k<=j;k++)h=(h|a[i]);
			if(h==k)maxx=max(maxx,j-i+1);
		}
	}
	cout<<maxx;
	return 0;
	
}
