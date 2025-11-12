#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,v;
	cin>>m>>n;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m);
	reverse(a+1,a+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) v=i;
	}
	cout<<(v-1)/n+1<<" ";
	if(((v-1)/n+1)%2==1){
		if(v%n==0) cout<<n;
		else cout<<v%n;
	}
	else{
		cout<<n+1-v%n;
	}
	return 0;
}
