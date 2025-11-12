#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=105;
int n,m,a[N],it;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	m*=n;
	for(int i=1;i<=m;++i) cin>>a[i];
	it=a[1];
	sort(a+1,a+m+1,greater<int>());
	for(int i=1;i<=m;++i){
		if(it==a[i]){
			it=i;
			break;
		}
	}
	cout<<(it-1)/n+1<<" ";
	if((it-1)/n%2==1){
		if(it%n==0) cout<<1;
		else cout<<n-it%n+1;
	}else{
		if(it%n==0) cout<<n;
		else cout<<it%n;
	}
	return 0;
} 
