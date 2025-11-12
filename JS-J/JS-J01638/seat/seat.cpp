#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<y<<' '<<x;
			return 0;
		}
		if(y%2){
			if(x==n) y++;
			else x++;
		}else{
			if(x==1) y++;
			else x--;
		}
	}
	return 0;
}
