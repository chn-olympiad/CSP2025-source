#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			int a1=(i+n-1)/n;
			int a2=i-n*(a1-1);
			if(!(a1&1)) a2=n-a2+1;
			cout<<a1<<" "<<a2<<endl;
			return 0;
		}
	}
	return 0;
}

