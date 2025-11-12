#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[105];
long long b,bi,l;
bool tamp(long long x,long long y){
	if(x<y) return false;
	return true;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	b=a[1];
	sort(a+1,a+n*m+1,tamp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			bi=i;
			break;
		}
	}
	
	if(bi%n==0){
		l=bi/n;
		cout<<bi/n<<" ";
	}else if(bi%n!=0){
		l=bi/n+1;
		cout<<bi/n+1<<" ";
	}
	if(l%2!=0){
		if(bi%n==0){
			cout<<n;
		}else{
			cout<<bi%n;
		}
	}else if(l%2==0){
		cout<<n-bi%n+1;
	}
	return 0;
}