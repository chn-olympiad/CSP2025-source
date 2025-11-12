#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,a[100001];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(k==0){
		int ans=0;
		for(int i=0;i<n;i++)
			if(a[i]==0)
				ans++;
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		if(a[i]==1)
			ans++;
	cout<<ans;
	return 0;
}
