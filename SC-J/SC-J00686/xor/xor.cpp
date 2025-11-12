#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans,a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans=k;
		if(a[i]==k&&a[i]==0){
			ans=1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
