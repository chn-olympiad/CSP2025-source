#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll a[N],m,n,xs,lie,hang,qu,wei;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=m*n;i++) cin>>a[i];
	xs=a[1];
	sort(a+1,a+m*n+1,greater<int>());
	for(ll i=1;i<=m*n;i++){
//		cout<<a[i];
		if(a[i]==xs) xs=i;
	} 
//	cout<<xs<<"\n";
	if(xs%n==0) lie=xs/n;
	else lie=xs/n+1;
	if(xs%(2*n)==0){
//	 	qu=m*n/(2*n);
//		wei=2*n;
		hang=1;
	}
	else {
	 	qu=m*n/(2*n)+1;
	 	wei=xs%(2*n);//yu
	 	if(wei<=n) hang=wei;
	 	else hang=2*n+1-wei;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 