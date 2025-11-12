#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],x,k;
bool cmp(int &X,int &Y){
	return X>Y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
//			cout<<i<<' ';
			k=i/n;
			if(i%n==0){
				if((i/n)%2){
					cout<<i/n<<' '<<n;
				}
				else{
					cout<<i/n<<' '<<1;
				}
			}
			else{
				if((k+1)%2){
					cout<<k+1<<' '<<i-k*n;
				}
				else{
					cout<<k+1<<' '<<n-(i-k*n)+1; 
				}
			}
		}
	}
	return 0;
}

