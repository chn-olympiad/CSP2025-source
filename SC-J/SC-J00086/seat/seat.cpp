#include<iostream>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={},cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]){
			cnt++;
		}
	}
	//cout<<cnt;
	int c=cnt/n,r;
	if(cnt%n==0){
		if(c%2==1){
			r=n;
		}else{
			r=0;
		}
	}else{
		c++;
		if(c%2==1){
			r=cnt%n;
		}else{
			r=n-(cnt%n)+1;
		}
	}
	cout<<c<<' '<<r;
}