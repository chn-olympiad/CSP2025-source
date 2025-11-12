#include<bits/stdc++.h>
using namespace std; 
int n,m,cnt;
int num;
int l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>num;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>num) cnt++;
	}
	cnt++;
	if(cnt%n==0){
		l=cnt/n;
		cout<<cnt/n<<" ";
	}else{
		l=(cnt/n)+1;
		cout<<(cnt/n)+1<<" ";
	}
	if(l%2==0){
		if(cnt%n==0) cout<<1;
		else cout<<n-(cnt%n)+1;
	}else{
		if(cnt%n==0) cout<<n;
		else cout<<cnt%n;
	}
	return 0;
} 

