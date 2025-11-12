#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	map<pair<int,int>,int> kmap,choose;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			int value=(j==i?a[j]:value xor a[j]); 
			if(value==k) kmap[pair<int,int>(i,j)]=1;
		}
	}
//	while(!kmap.empty()) {
//		for(auto i:kmap) {
//			
//		}
//	}
	bool flag=true;
	for(int i=1;i<=n;i++) {
		if(a[i]==1&&flag) continue;
		else flag=false;
	}
	if(flag&&k==0) cout<<n;
	else cout<<kmap.size();
} 
