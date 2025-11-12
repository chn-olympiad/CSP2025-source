#include<bits/stdc++.h>
using namespace std;
int a[250];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int x;
	if(cnt%n==0){
		x=cnt/n;
	}else{
		x=cnt/n+1;
	}
	cout<<x<<" ";
	if(cnt%n==0){
		if(x%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		if(x%2==0){
			cout<<n-cnt%n+1;
		}else{
			cout<<cnt%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
