#include <bits/stdc++.h>
using namespace std;
int n,k,ans; 
int a[100005];
int v[10005][10005];
int ans2[10005][10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans2[i][i]=a[i];
		if(a[i]==k){
			ans++;
			v[i][i]=1;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			ans2[i][j]=ans2[i][i]^ans2[i+1][j];
			v[i][j]=max(v[i+1][j],max(v[i][i],max(v[i][j-1],v[j][j])));
			if(ans2[i][j]==k&&v[i][j]==0){
					v[i][j]=1;
					ans++;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
