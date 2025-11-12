#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	int temp1;
	cin>>temp1;
	int max=temp1;
	for(int i=2;i<=m*n;i++){	
		int temp[i];
		cin>>temp[i];
		if(temp[i]>=max){
			cnt++;
		}
	}
	int c,r;
	if(cnt%n==0){
		c=cnt/n;
		r=n;
	}
	if(cnt/n<1&&cnt%n!=0){
		c=1;
		r=cnt%n;
	}
	if(cnt/n>1&&cnt%n!=0){
		c=cnt/n+1;
		r=cnt%n;
	}
	cout<<c<<" "<<r;
	return 0;
}