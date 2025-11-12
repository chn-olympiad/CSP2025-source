#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],pm=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>=a[1]) pm++;
	}if(((pm-1)/n)%2==0){
		cout<<(pm-1)/n+1<<" "<<(pm-1)%n+1;
	}else{
		cout<<(pm-1)/n+1<<" "<<n-(pm-1)%n;
	}
}