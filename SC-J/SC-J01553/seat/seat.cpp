#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt=1,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>q;
		if(q>a)cnt++;
	}
	int k=cnt/m;
	if(cnt%m==0){
		cout<<k<<" ";
		k--;
	}else{
		cout<<k+1<<" ";
	}
	if(k%2==0){
		if(cnt%n==0)cout<<n;
		else cout<<cnt%n;
	}else{
		if(cnt%n==0)cout<<"1";
		else cout<<n-cnt%n+1;
	}
	return 0;
}