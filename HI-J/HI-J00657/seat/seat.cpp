#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int fal=0;
	fal=a[1];
	int x=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>fal){
			x++;
		}
	}
	x++;
	if(x%n!=0){
		if(((x/n)+1)%2!=0){
			cout<<(x/n)+1<<" "<<x%n;
		}else{
			cout<<(x/n)+1<<" "<<n-(x%n)+1;
		}
	}else{
		if((x/n)%2!=0){
			cout<<x/n<<" "<<n;
		}else{
			cout<<x/n<<" "<<1;
		}
	}
	
	return 0;
}
