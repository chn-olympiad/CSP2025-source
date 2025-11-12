#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,greater<int>());
//	for(int i=1;i<=n*m;++i) cout<<a[i]<<' ';
	
	for(int i=1;i<=n*m;++i){
		if(a[i]==k){
//			cout<<i<<endl;
			int hang,lie;
			lie=(i-1)/n+1;
			hang=i-(lie-1)*n;
			if(lie%2==0) hang=n-hang+1;
			cout<<lie<<' '<<hang<<endl;
			return 0;
		}
	}
	return 0;
}

