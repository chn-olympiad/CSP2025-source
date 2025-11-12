#include<bits/stdc++.h> 
using namespace std;
int m,n,cnt=1;
long long a[105],b[105];
int main(){
	freopen('seat.in','r',stdin);
	freopen('seat.out','w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=100;i>a[1];i--){
		if(b[i]!=0){
			cnt++;
		}
	}
	int c=cnt/n;
	int r=cnt%n;
	if(c%2==0){
		r=n-r;
	}
	cout<<c<<" "<<r;
	return 0;
}
