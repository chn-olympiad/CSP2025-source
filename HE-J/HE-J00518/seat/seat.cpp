#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,a[100010],b;
	int f=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m);
	for(int i=m*n;i>=1;i--){
		if(a[i]!=b){
			if(f){
				r++;
			}else{
				r--;
			}
			if(r>n){
				r--,c++,f=1-f;
			}
			if(r<1){
				r++,c++,f=1-f;
			}
		}
		else{
			break;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
