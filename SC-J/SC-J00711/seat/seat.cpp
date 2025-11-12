#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
struct a{
	int sroce,id;
}b[105];
bool cmp(a x,a y){
	return x.sroce>y.sroce;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i*n+j].sroce;
			b[i*n+j].id=i*n+j;
		}
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i].id==1){
			int x=(i+m-1)/m;
			if(x%2==1&&i%n!=0){
				cout<<x<<' '<<i%n;
			}else if(x%2==1&&i%n==0){
				cout<<x<<' '<<n;
			}
			else if((n*m-i+1)%n!=0){
				cout<<x<<' '<<(n*m-i+1)%n;
			}else{
				cout<<x<<' '<<n;
			}
		}
	}
	return 0;
}
