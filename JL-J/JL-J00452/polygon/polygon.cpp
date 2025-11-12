#include <bits/stdc++.h>
using namespace std;
long long n,a[5001],ans=0,maxn=-1,h=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		h+=a[i];
	}
	if(h>2*maxn) ans++;
	cout<<ans<<endl;
	return 0;
}
