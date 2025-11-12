#include<bits/stdc++.h>
using namespace std;
#define N 105
int n,m,k,x;
int a[N];
void init(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
void collect(){
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+k+1,greater<int>());
}
void work(){
	int order=find(a+1,a+k+1,x)-(a+1);
	//cerr<<x<<' '<<a[order+1]<<endl<<order<<endl;
	int row=(order)/n+1,column;
	if(row&1){//奇数
		column=(order)%n+1;
	}else{
		column=n-order%n;
	}
	cout<<row<<' '<<column;
}
void solve(){
	collect();
	work();
}
int main(){
	init();
	solve();
	return 0;
}