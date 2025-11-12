#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n,a[N],m,x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];	
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			x=i;
			break;
		}
		
	}
	cout<<(x+n-1)/n<<" ";
	if(x%(2*n)==0){
		cout<<1;	
	}else if(x%(2*n)>n){
		cout<<2*n-x%(2*n)+1;
	}else{
		cout<<x%(2*n);	
	}
}