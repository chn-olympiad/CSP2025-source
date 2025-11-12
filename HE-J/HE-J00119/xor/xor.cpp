#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,k;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i])
				ans++;
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!a[i])ans++;
			else if(a[i-1])a[i]=0,ans++;
		}
	}
	cout<<ans;
	return 0;
}
