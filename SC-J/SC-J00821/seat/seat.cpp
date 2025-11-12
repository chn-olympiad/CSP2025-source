#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,i,j,x=1,y=1,tmp;
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+n*m+1);
	for(i=n*m;i>=1;i--){
		if(a[i]==tmp){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2){
			if(x<n) x++;
			else y++;
		}
		else{
			if(x>1) x--;
			else y++;
		}
	}
	return 0;
}