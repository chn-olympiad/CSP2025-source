#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
unordered_map<long,int> um;
long long k,ans,a[N];
int x;
int main(){
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
  ios::sync_with_stdio(false);
	cin>>n>>k;
	um[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans^=a[i]; 
		//if(i==1)ans=a[i]; 
		//else ans^=a[i];
		if(um[ans^k]) um.clear(),ans=0,um[0]=1,x++;
	//	for(auto t:um) cout<<t.first<<" "<<t.second<<"\n";
		um[ans]++;
		// bless me!
		// pray for me!
		// Draco & Echo
	}
	cout<<x;
	return 0;
}
