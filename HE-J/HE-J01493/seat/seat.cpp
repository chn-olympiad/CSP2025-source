#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+m*n+1);
	int c=1,r=0;
	for(int i=n*m;i;--i){
		if(c%2==1){
			r++;
			if(r>n){
				c++;
				r=n;
			}
		}else if(c%2==0){
			r--;
			if(r<1){
				c++;
				r=1;
			}
		}
		
		if(a[i]==a1){
			break;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
