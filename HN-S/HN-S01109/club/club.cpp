#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+8;
struct www{
	int x1,x2,x3,q;
}a[N];
bool cmp(www x,www y){
	return x.x1>y.x1;
}
bool cmp1(www x,www y){
	return x.q>y.q;
}
void solve(){
	cin>>n;
	int ss=1;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x1>>a[i].x2>>a[i].x3;
		if(a[i].x2!=0||a[i].x3!=0) ss=0;
		a[i].q=a[i].x1-a[i].x2;
	}
	if(ss){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			num+=a[i].x1;
		}
		cout<<num<<'\n';
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			num+=a[i].x1;
		}
		for(int i=n/2+1;i<=n;i++){
			num+=a[i].x2;
		}
		cout<<num<<'\n';
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
} 
