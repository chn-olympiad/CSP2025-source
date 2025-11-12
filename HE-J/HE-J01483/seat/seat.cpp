#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			x=(i-1)/n+1;
			if(x%2==1){
				y=i-(x-1)*n;
			}else if(x%2==0){
				y=n-(i-(x-1)*n)+1;
			}
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
