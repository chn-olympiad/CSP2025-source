#include <bits/stdc++.h>
using namespace std;
int a[10005];
int f(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=a[1];
	sort(a+1,a+n*m+1,f);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cnt=i;
			break;
		}
	}
	int c=0;
	if(cnt%n!=0){
		cout<<cnt/n+1<<' ';
		c=cnt/n+1;
	}
	else{
		cout<<cnt/n<<' ';
		c=cnt/n;
	}
	if(c%2!=0){
		if(cnt%2==0) cout<<n-cnt%n;
		else cout<<cnt%n;
	}else{
		if(cnt%2==0) cout<<n-cnt%n;
		if(cnt%2!=0) cout<<n-cnt%n+1;
	}
	return 0;
}
