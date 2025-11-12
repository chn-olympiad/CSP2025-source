#include<bits/stdc++.h>
using namespace std;
int n;
int a[701100];
int maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		cout<<(a[1]+a[2]>a[3]);
	}
	return 0;
}
