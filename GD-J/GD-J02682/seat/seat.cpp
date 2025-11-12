#include<bits/stdc++.h> 
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,z=1;
	cin>>n>>m>>k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>k){
			z++;
		}
	}
	if(z%n==0){
		if((z/n)%2==0){
			cout<<z/n<<" "<<1<<endl;
		}else{
			cout<<z/n<<" "<<n<<endl;
		}
	}else{
		if((z/n+1)%2==1){
			cout<<z/n+1<<" "<<z%n<<endl;
		}else{
			cout<<z/n+1<<" "<<n-(z%n)+1<<endl;
		}
	}
	return 0;
}
