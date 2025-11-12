#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt];
			cnt++;
		}
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=1,f=0;
	for(int i=n*m;i>=1;i--){
//		cout<<a[i]<<" "<<x<<" "<<y<<endl;
		if(a[i]==ans){
			cout<<x<<" "<<y;
			return 0;
		}
		if(!f){
			y++;
			if(y>n){
				f=1;
				y=n;
				x++;
			}
		}
		else{
			y--;
			if(y==0){
				f=0;
				y=1;
				x++;
			}
		}
	}
	return 0;
}
