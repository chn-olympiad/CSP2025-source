#include<bits/stdc++.h>
using namespace std;

int n,m,c,cnt=1;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>=c) cnt++;
	}
	if(cnt%n==0){
		if((cnt/n)%2==0)
			cout<<cnt/n<<" "<<1;
		else
			cout<<cnt/n<<" "<<m;
	}else{
		if(int(cnt/n+1)%2==0){
			cout<<int(cnt/n+1)<<" "<<int(cnt/n+1)*n-cnt+1;
		}else{
			cout<<int(cnt/n+1)<<" "<<cnt-int(cnt/n)*n;
		}
	}
	return 0;
}
