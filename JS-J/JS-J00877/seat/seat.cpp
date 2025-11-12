#include<bits/stdc++.h>
using namespace std;
int n,m,rsc,rra;
vector<int>a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a.resize(n*m+1,0);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)rsc=a[i];
	}
	sort(a.begin()+1,a.end(),greater<int>());
	for(int i=1;i<=n*m;i++)if(a[i]==rsc)rra=i;
	int l=(rra+n-1)/n,h;
	if(l%2==1)h=rra%n;
	else h=n-rra%n+1;
	cout<<l<<' '<<(h==0?n:h);
	return 0;
}
