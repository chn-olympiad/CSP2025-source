#include<bits/stdc++.h>
using namespace std;
int m,n,l=1;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			l++;
		}
	}
	int cnt=l%n;
	l-=cnt;
	if((l/n)%2==1){
		if(cnt==0){
			cout<<l/n<<" "<<n;
		}else{
			cout<<l/n+1<<" "<<n-cnt+1;
		}
	}else{
		if(cnt==0){
			cout<<l/n<<" "<<1;
		}else{
			cout<<l/n+1<<" "<<cnt;
		}
	}
	return 0;
}
