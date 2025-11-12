#include<bits/stdc++.h>
using namespace std;
int n,m,z,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>z;
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>z){
			cnt++;
		}
	}
	cnt+=1;
	int x=cnt/n,y=cnt%n;
	if(y==0){
		if(x%2)cout<<x<<' '<<n;
		else cout<<x<<' '<<1;
	}
	else if(x==0)cout<<1<<' '<<y;
	else{
		cout<<x+1<<' '<<y+1;
	}
	return 0;
}