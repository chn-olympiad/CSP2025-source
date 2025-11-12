#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[150];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	int r=a[1],w;
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;i++){
		if(a[i]==r){
			w=i;
			break;
		}
	}
	int l=0,h=0;
	l=(w-1)/n+1;
	int d=(w-1)%(n*2);
	if(d<n){
		h+=(w-1)%n+1;
	}else{
		int hh=(w-1)%n;
		h+=n-hh;
	}
	cout<<l<<" "<<h;
	return ;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	solve();
	return 0;
}
