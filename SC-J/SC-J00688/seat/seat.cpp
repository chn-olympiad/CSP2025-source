#include<bits/stdc++.h>
using namespace std;
int n,m;
int f;
int cnt;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>=f){
			cnt++;
		}
	}
	cout<<(cnt-1)/n+1<<' ';
	if(((cnt-1)/n+1)%2==0){
		cout<<m-(cnt-1)%n;
	}else{
		cout<<(cnt-1)%n+1;
	}
	return 0;
}