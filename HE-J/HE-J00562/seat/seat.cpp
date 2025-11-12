#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],q; 
bool c(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+n*m+1,c);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p) q=i;
	}
	int t=q/n;
	if(q%2==0){
		cout<<t<<" "<<n-q%n;
	}
	else cout<<t+1<<" "<<q%n+1;
	
	
	return 0;
} 
