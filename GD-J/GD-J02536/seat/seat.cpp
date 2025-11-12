#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)continue;
		if(a[i]>a[1]){
			cnt++;
		}
	}
	cnt++;
	int l=(cnt-1)/n+1,c=(cnt-1)%n+1,h;
	if(l%2==0)h=n+1-c;
	else h=c;
	cout<<l<<' '<<h;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
