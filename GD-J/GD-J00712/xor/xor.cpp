#include<bits/stdc++.h>
using namespace std;

const long long MAXN=5e5;
long long n,k;
int ans=0;
int a[MAXN+5];

int weight(int l,int r){
	if(l==r){
		return a[l];
	}
	int sum=a[l];
	for(int j=l+1;j<=r;j++){
		sum=sum^a[j];
	}
	return sum;
}

int dfs(int s){
	for(int d=s;d<=n;d++){
		int w=weight(s,d);
		if(w==k){
			return 1+(d<n?dfs(d+1):0);
		}
	}
	return 0;
}

int main(){
	//AC from 1 to 4.
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dfs(i));
	}
	cout<<ans;
	return 0;
}
