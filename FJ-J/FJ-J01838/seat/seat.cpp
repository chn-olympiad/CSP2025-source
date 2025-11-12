#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			d++;
		}
	}
	if(d%n==0){
		cout<<d/n<<" ";
		if((d/n)%2){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		cout<<d/n+1<<" ";
		if((d/n+1)%2){
			cout<<d-d/n*n;
		}else{
			cout<<n-(d-d/n*n)+1;
		}
	}
	return 0;
}

