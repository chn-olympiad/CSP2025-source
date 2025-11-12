#include<bits/stdc++.h>
using namespace std;
const int maxn=5001;
int n,a[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=a[1],sum=a[1];
	for(int i=2;i<=n;i++){
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	cout<<(sum>2*mx)<<endl;
	return 0;
}
/*

*/
