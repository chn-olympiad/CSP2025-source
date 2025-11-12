#include<bits/stdc++.h>
using namespace std;
long long n,m,a,num,cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
			num=a;
			cnt++;
		}else if(a>num){
			cnt++;
		}
	}
	if(cnt%n==0){
		c=cnt/n;
	}else{
		c=cnt/n+1;
	}
	if(cnt%(2*n)>=1&&cnt%(2*n)<=n){
		r=cnt%(2*n);
	}else if(cnt%(2*n)==0){
		r=1;
	}else{
		r=2*n-cnt%(2*n)+1;
	}
	cout<<c<<" "<<r;
	
	return 0;
} 