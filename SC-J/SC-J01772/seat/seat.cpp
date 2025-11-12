#include<bits/stdc++.h>
using namespace std;
int n,m,cj[105],r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
		if(cj[i]>cj[1]){
			r++;
		}
	}
	if(r%n!=0){
		if(r/n%2==0){
			cout<<r/n+1<<" "<<r%n;
		}else{
			cout<<r/n+1<<" "<<n-r%n+1;
		}
	}else{
		if(r/n%2==0){
			cout<<r/n<<" "<<1;
		}else{
			cout<<r/n<<" "<<n;
		}
	}
	return 0;
}