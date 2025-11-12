#include<bits/stdc++.h>
using namespace std;
int n,m,b,c;
int a[10005];
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			c=n*m-i;
			break;
		}
	}
	if(c%n==0){
		f=true;
	}
	if(((c+n-1)/n)%2==1){
		if(f){
			cout<<(c+n-1)/n<<' '<<n;
		}else{
			cout<<(c+n-1)/n<<' '<<c%n;
		}
	}else{
		if(f){
			cout<<(c+n-1)/n<<' '<<1;
		}else{
			cout<<(c+n-1)/n<<' '<<n-(c%n-1);
		}
	}
	return 0;
}
