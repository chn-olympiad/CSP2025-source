#include<bits/stdc++.h>
using namespace std;
int a[128];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n,m,s;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)cin>>a[i];
	s = a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int i = 0,j = 1,tot = 0;
	while(tot<n*m){
		while(i<n){
			i++,tot++;
			if(a[tot]==s){
				cout<<j<<' '<<i;
				return 0;
			}
		}
		j++,tot++;
		if(a[tot]==s){
			cout<<j<<' '<<i;
			return 0;
		}
		while(i>1){
			i--,tot++;
			if(a[tot]==s){
				cout<<j<<' '<<i;
				return 0;
			}
		}
		j++,tot++;
		if(a[tot]==s){
			cout<<j<<' '<<i;
			return 0;
		}
	}
	return 0;
}
