#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,x,y;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	//cout<<k<<' ';
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1;
	for(int i=1;i<=n*m;i++){
		//cout<<x<<' '<<y<<'\n';
		if(a[i]==k){
			cout<<x<<' '<<y;
			break;
		}
		if(y==n && x%2==1){
			y=n;
			x++;
			//cout<<"-1\n";
		}
		else if(y==1 && x%2==0){
			y=1;
			x++;
			//cout<<"-2\n";
		}
		else if(x%2==1) y++;
		else if(x%2==0) y--;
	}
	return 0;
}
