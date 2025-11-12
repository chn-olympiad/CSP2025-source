#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500050],b[500050];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) b[i]=a[i];
		else b[i]=b[i-1]^a[i];
	}
	
	int ans=0,idx=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=idx;j<i;j++){
			if((b[i]^b[j])!=k){continue;}
			u=1;idx=i;
		}
		ans+=u;
	}
	
	cout<<ans;
	
	return 0;
} 
