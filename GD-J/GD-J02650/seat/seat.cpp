#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct xxs{
	int id;
	int g;
};
bool cmp(xxs x,xxs y){
	return x.g>y.g;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	xxs a[n*m+10];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].g;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%n==0){
				cout<<i/n<<' ';
				if((i/n)%2==0) cout<<1;
				else cout<<n;
				break;
			}
			else{
				cout<<i/n+1<<' ';
				if((i/n+1)%2==1) cout<<i%n;
				else cout<<i-i%n; 
			}
			
		} 
	}
	return 0;
}
