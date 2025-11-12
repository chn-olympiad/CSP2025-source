#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=0;i<n;i++){
			Max=max(a[i],Max);
			s+=a[i];
		}
		if(s>2*Max)
			ans++;
	}
	cout<<ans;
	return 0;
}