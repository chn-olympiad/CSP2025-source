#include<bits/stdc++.h>
using namespace std;
long long n,t,as,bs,cs,a[100005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>as>>as;
		}
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--){
			bs+=a[i];
		}
		cout<<bs;
	}
	return 0;
}
