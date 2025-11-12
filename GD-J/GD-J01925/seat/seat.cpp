#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
long long n,m,a[maxn],mR=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])mR++;
	}
	cout<<mR/n+(mR%n>0)<<" ";
	if((mR/n+(mR%n>0))%2)cout<<(mR%n ? mR%n:n)<<'\n';
	else cout<<(mR%n ? n-(mR%n)+1:1)<<'\n';
	return 0;
}
