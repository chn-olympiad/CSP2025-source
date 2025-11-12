#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int ma=INT_MIN;
int s;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	int k=n-1;
	for(int i=1;i<=n;i++){
		if(n==3){
			if(a[i]!=ma)
				s+=a[i];
		}
	}
	if(s>ma) cout<<"1";
	else cout<<"0";
	return 0;
}
