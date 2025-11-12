#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[200],cnt=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int c;
	if(cnt%n==0){
		c=cnt/n-1;
	}else{
		c=cnt/n;
	}
	if(c%2==0){
		cout<<c+1<<" "<<cnt-c*n;
	}else{
		cout<<c+1<<" "<<n-cnt+c*n+1;
	}
	 
	
	return 0;
}
