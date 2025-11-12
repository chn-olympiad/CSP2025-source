#include <bits/stdc++.h>
using namespace std;
int m,n,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<m*n;i++){
		cin >>a[i];
	}
	int ans=a[0];
	sort(a,a+m*n,cmp); 
	for(int i=0;i<m*n;i++){
		if(a[i]==ans) {
			ans=i+1;
			break;
		}
	}
	if(ans%n==0) {
		cout <<ans/n<<" ";
		cout <<n;
	}
	else{
		cout <<ans/n+1<<" ";
		if((ans/n+1)%2==1) cout <<ans%n;
		else cout <<n-ans%n+1;
	}
	return 0;
}
