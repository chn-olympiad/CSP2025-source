#include<bits/stdc++.h>
using namespace std;
int num,r,n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int cnt = 1;
	cin>>n>>m>>r;
	for(int i = 0;i < n*m-1;i++){
		cin>>num;
		if(num>r) cnt++;
	}
	int s;
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if((cnt/n)%2==0) cout<<1;
	    else cout<<n;
	}
	else {
		cout<<cnt/n+1<<" ";
	    if((cnt/n+1)%2==0) cout<<n-cnt%n+1;
	    else cout<<cnt%n;
    }
    return 0;
}
