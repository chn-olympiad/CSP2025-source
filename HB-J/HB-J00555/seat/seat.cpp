#include<bits/stdc++.h>
using namespace std;
int a[101],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int x=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			x++;
		}
	}
	if(x<=n){
		cout<<1<<" "<<x;
	}
	else{
		cout<<ceil(1.0*x/n);
		if(int(ceil(1.0*x/n))%2==0){
			cout<<" "<<n-((x%n)-1);
		}
		else{
			cout<<" "<<x%n;
		}
	}
	return 0;
}
