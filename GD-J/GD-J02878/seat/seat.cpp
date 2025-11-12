#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==w) b=i;
	}
	if(b%n==0) cout<<b/n<<" ";
	else cout<<b/n+1<<" ";
	if(b/n%2==0){
		if(b%n==1||b%n==0) cout<<1<<endl;
	    else cout<<b%n<<endl;
	}
	else {
		if(b%n==1||b%n==0) cout<<n<<endl;
	    else cout<<n-b%n<<endl;
	}
	return 0;
}
