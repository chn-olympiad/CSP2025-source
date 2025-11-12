#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans;
map<int,bool>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;mp.clear();
			continue;
		}
		mp[t^k]=true;
		if(mp[t^a[i]]){
			ans++;
			mp.clear();
		}else{
			t^=a[i];
			mp[t^k]=true;
		}
	}
	cout<<ans;
	return 0;
}
