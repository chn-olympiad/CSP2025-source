#include<bits/stdc++.h>
using namespace std;


int a[1000],r;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int seat=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			seat=i;
			break;
		}
	}
	
	if(seat%n==0){
		cout<<seat/n<<" "<<m;
	}else{
		cout<<seat/n+1<<" ";
		if((seat/n)%2==0){
			cout<<seat%n;
		}else{
			cout<<m-seat%n+1;
		}
	}
	
	
	
	return 0;
} 
