#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	vector<int>a(n+1),pre(n+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int ans=0;
	for(int i=1,j=1;i<=n&&j<=n;j++){
		int cnt=0;
		if(int(pre[j]^pre[i-1])==k){
			ans++,i=j+1;
		}
		if(j==n) i++,j=i,ans=max(ans,cnt+ans);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

