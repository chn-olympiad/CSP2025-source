#include<iostream>
#include<cstdio>
using namespace std;
int a1,a,n,m,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>a1){
			cnt++;
		}
	}
	int i=1+(cnt-1)/n,j=(cnt-1)%n+1;
	if(i%2==0){
		j=n-j+1;
	}
	cout<<i<<" "<<j;
	return 0;
}