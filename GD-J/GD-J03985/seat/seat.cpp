#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N*N];
int ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==ans) break;
		if(x%2==1){
			if(y+1>n) x++;
			else y++;
		}
		else{
			if(y-1<=0) x++;
			else y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
