#include<bits/stdc++.h>
using namespace std;
int n,m,scr;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	a.clear();
	cin>>n>>m;
	a.resize(n*m+1);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	scr=a[1];
	sort(&a[1],&a[n*m],cmp);
	int c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==scr){
			c=(i+n-1)/n;
			r=i%n;
			if(c%2==0){
				r=n-r+1;
			}
			cout<<c<<' '<<r;
		}
	}
	return 0;
}
