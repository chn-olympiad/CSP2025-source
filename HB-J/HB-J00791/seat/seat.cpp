#include <iostream>
#include <cstdio>
#include <algorithm>
bool cmp(int x,int y){
	return x>y;
}
using namespace std;
int n,m,seat[105],r,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>seat[i];
	}
	r=seat[1];
	sort(seat+1,seat+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(seat[i]==r){
			a=i;
			break;
		}
	}
	if(((a-1)/n)%2==1){
	    cout<<((a-1)/n+1)<<' ';
	    if(a%n==0){
			cout<<1;
		}else{
			cout<<n-a%n+1;
		}
	}else{
		cout<<((a-1)/n+1)<<' ';
		if(a%n==0){
			cout<<n;
		}else{
			cout<<a%n;
		}
	}
    return 0;
} 
