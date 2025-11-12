#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x=0,cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	while(x<n){
		x++;
		for(int i=1;i<=m;i++){
			cnt++;
			if(a[cnt]==r){
				cout<<x<<" "<<i;
				return 0;
			}
		}
		if(x==n){
			break;
		}
		x++;
		for(int i=m;i>=1;i--){
			cnt++;
			if(a[cnt]==r){
				cout<<x<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
