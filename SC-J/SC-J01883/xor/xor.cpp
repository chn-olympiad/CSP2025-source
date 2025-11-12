#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
const int N=5e5+10;
int a[N];
bool sf1=true,sf=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&sf1) sf1=false;
		if(a[i]>1&&sf) sf=false;
	}
	if(sf1){
		cout<<n;
		return 0;
	}
	if(sf&&k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}else if(sf&&k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}