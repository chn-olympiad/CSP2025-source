#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
int n,m,c,r;
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
void solve(int k,int n,int m){
	cout<<(int)ceil((k+0.0)/n)<<' ';
	if((int)ceil((k+0.0)/n)%2==1){
		if(k%n==0){
			cout<<n;
			return;
		}
		cout<<k%n;
	}else{
		if(k%n==0){
			cout<<1;
			return;
		}
		cout<<n-k%n+1;
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			r=i;
			break;
		}
	}
	solve(r,n,m);
	return 0;
}
