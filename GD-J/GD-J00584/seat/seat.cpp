#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],ff=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			ff++;
		}
	}
	int h=ff/n,l=ff%n;
	if(l==0){
		if(h%2==0){
			cout<<h<<" "<<1<<endl;
		}else{
			cout<<h<<" "<<n<<endl;
		}
	}else{
		if((h+1)%2==0){
			cout<<h+1<<" "<<n-l+1<<endl;
		}else{
			cout<<h+1<<" "<<l<<endl;
		}
	}
}
