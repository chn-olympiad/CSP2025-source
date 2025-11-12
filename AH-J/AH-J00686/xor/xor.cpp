#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++,cnt=0;
			else{
				if(cnt==1) ans++,cnt=0;
				else cnt=1;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
