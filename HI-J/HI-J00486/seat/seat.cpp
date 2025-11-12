#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i])
		cnt++;
	}
	int b=cnt/n,c=cnt%n;
	if(cnt<n)cout<<b+1<<" "<<c+1;
	if(cnt>n||cnt==n){
		if((b+1)%2==0)cout<<b+1<<" "<<n-c;
		else cout<<b+1<<" "<<c+1;
	} 
	return 0;
}
