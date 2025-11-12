#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[2000005],n,m,u,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>u;
		b[t]=i;
		t^=u;
		if(b[t^m]==0){
			a[i]=a[i-1];
		}
		else{
			a[i]=max(a[i-1],a[b[t^m]-1]+1);
		}
	}
	cout<<a[n];
	return 0;
} 