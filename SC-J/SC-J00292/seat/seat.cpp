#include<bits/stdc++.h>
using namespace std;
int n,m,u;
int a[10003];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	u=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			u=i;
			break;
		}
	}
	if((u-1)/n%2==1){
		cout<<(u-1)/n+1<<" "<<n+1-((u%n==0)?n:u%n);
	}
	else{
		cout<<(u-1)/n+1<<" "<<((u%n==0)?n:u%n);
	}
	return 0;//bbbbbbbbbbbbbbbbbbb
}