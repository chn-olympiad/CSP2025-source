#include<bits/stdc++.h>
using namespace std;
int n,m,ar[110],a,w,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>ar[i];
	}
	a=ar[1];
	sort(ar+1,ar+1+z);
	for(int i=1;i<=z;i++){
		if(ar[i]==a){
			w=z-i+1;
			break;
		}
	}
	if(w%n==0){
		cout<<w/n<<" ";
		if((w/n)%2==1){
			cout<<n;
		}else{
			cout<<"1";
		}
	}else{
		cout<<w/n+1<<" ";
		if((w/n+1)%2==1){
			cout<<w%n;
		}else{
			cout<<n-(w%n)+1;
		}
	}
	return 0;
} 
