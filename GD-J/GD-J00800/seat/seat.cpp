#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int p=a[1],cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>p)cnt++;
	}
	int x=ceil(1.0*cnt/n);
	int y=cnt%n;
	if(y==0)y=n;
//	cout<<cnt<<" "<<x<<" "<<y<<'\n';
	if(x%2==1){
		cout<<x<<" "<<y<<'\n';
	}else{
		cout<<x<<" "<<n-y+1<<'\n';
	}
	return 0;
}/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
