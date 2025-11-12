#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105];
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int rr=a[1];
	//cout<<rr<<'\n';
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
	//	cout<<a[i]<<" ";
		if(rr==a[i]){
			rr=i;
			break;
		}
	}
	//cout<<rr<<" \n";
	int h=0,l=0;
	l=(rr+n-1)/n;
	h=rr%(2*n);
	cout<<l<<" ";
	if(h<=n){
		cout<<h;
	}else{
		cout<<2*n-h+1;
	}
	return 0;
}
