#include <bits/stdc++.h>
using namespace std;
int n,k,m,ans;
int l[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		m=m^l[i];
		if(m==k){
			m=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
