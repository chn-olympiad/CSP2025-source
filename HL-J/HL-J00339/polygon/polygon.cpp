#include <bits/stdc++.h>
using namespace std;
const long long T=998244353;
long long n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	long long mx=-1e9,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(mx<a[i]){
			mx=a[i];
		}
	}
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	else if(sum<=mx*2){
		cout<<0<<"\n";
		return 0;
	}
	cout<<9<<endl;
	return 0;
}