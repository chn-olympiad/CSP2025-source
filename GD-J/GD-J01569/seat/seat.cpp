#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int A;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	cin>>A;
	for(int i=2;i<=n*m;i++){
		int tmp;
		cin>>tmp;
		if(tmp>A){
			cnt++;
		}
	}
	int a=cnt/n;
	int b=cnt%n;
	cout<<a+1<<" ";
	if(a%2==0){
		cout<<b+1;
	}else{
		cout<<n-b;
	}
	return 0;
}

