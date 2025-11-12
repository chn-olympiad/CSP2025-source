#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	//freopen("seat.in","w",stdin);
	//freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,c=1,r=1;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>x){
			r++;
			if(r>m){
				if(c%2!=0){
					c++;
					r=c*n-r+1;
				}else{
					c++;
					r=r-m;
				}
			}
		}
	}
	cout<<c<<" "<<r;
}
