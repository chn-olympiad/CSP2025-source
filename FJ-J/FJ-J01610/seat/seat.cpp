#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=n*m-i+1;
			break;
		}
 	}
 	if(cnt%n==0){
 		if(cnt/n%2==0){
 			cout<<cnt/n<<" "<<1;
		}
		else{
 			cout<<cnt/n<<" "<<n;
		}
	}
	else if((cnt/n)%2==0){
		cout<<cnt/n+1<<" "<<cnt%n;
	}
	else{
		cout<<cnt/n+1<<" "<<n-cnt%n+1;
	}
	return 0;
}
