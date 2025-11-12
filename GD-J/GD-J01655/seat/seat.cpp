#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a,cnt=1;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int t1;
		cin>>t1;
		if(t1>a)cnt++;
	}
	if(((cnt-1)/n)%2==0){
		cout<<(cnt-1)/n+1<<" "<<(cnt-1)%n+1;
	}else{
		cout<<(cnt-1)/n+1<<" "<<n-(cnt-1)%n;
	}
	return 0;
}
