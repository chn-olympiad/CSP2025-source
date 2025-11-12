#include<bits/stdc++.h>
using namespace std;
const int N=500;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[N];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],seatt=1;
	for(int i=2;i<=n*m;i++){
		if(x<a[i])seatt++;
	}
	int i=ceil(seatt*1.0/n),j=0;
	j=(seatt%n==0?n:seatt%n);
	if(i%2==0){
		j=(n+1)-j;
	}
	cout<<i<<' '<<j;
	return 0;
}
