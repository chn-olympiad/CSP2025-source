#include <bits/stdc++.h>
using namespace std;
int n,a[5001],s;
bool db(int x,int y){
	int m,z=0;
	for(int i=x;i<y;i++){
		m=max(a[i],a[i+1]);
	}
	for(int i=x;i<=y;i++){
		z+=a[i];
	}
	if(z>(2*m)) return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(db(i,j)) s++;
		}
	}
	cout<<s%998%244%353;
}
