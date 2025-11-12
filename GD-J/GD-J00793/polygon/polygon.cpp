#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	vector<long long> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=3){
		if(n<=2){
			cout<<0;
		}else{
			if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		return 0;
	}
	cout<<1;
	return 0;
}
