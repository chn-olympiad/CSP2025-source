#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r;
int ch(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt,sum=a[1];
	sort(a+1,a+1+n*m,ch);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0)c=cnt/n;
	else{
		if(cnt<=n)c=1;
		else c=cnt/n+1;
	}
	if(c%2==0)r=n-cnt%n+1;
	else r=cnt%n;
	cout<<c<<" "<<r;
	return 0;
}
