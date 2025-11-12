#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,a[15][15],b[1000],x;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b+1,b+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(b[i]==x){
			x=i;
			break;
		}
	}
	if((x/n+1)%2!=0){
		if(x%n==0){
			cout<<x/n<<" "<<1;
		}else{
			cout<<x/n+1<<" "<<x%n;
		}
	}else{
		if(x%n==0){
			cout<<x/n<<" "<<n;
		}else{
			cout<<x/n+1<<" "<<n-x%n+1;
		}
	}
	return 0;
} 