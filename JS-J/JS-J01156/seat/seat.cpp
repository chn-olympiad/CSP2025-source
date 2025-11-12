#include<bits/stdc++.h>
using namespace std;
int n, m, k, x[110];
bool cmp(int a,int b){
		return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	x[1]=k;
	for(int i=2; i<=n*m; i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(x[i]==k){
			int ans=i%n;
			if(ans==0){
				cout<<i/n<<" ";
				if((i/n)%2==0){
					cout<<1;
					return 0;
				}else {
					cout<<n;
					return 0;
				}
			}else {
				cout<<i/n+1<<" ";
				if((i/n+1)%2==0){
					cout<<n-ans+1;
					return 0;
				}else {
					cout<<ans;
					return 0;
				}
			}
		}
	}
	return 0;
}
