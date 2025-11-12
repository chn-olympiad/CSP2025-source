#include<bits/stdc++.h>
using namespace std;
const int N=5007;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3){
		int maxx=-1,sum=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2) return cout<<1,0;
		else return cout<<0,0;
	}
	return 0;
	
}

