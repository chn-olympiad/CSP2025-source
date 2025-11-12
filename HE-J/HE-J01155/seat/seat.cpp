#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,f,cnt=1;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	f=n*m;
	for(int i=1;i<=f;i++) cin>>a[i];
	for(int i=2;i<=f;i++){
		if(a[i]>a[1]) cnt++;
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if((cnt/n)%2==0) cout<<1<<"\n";
		else cout<<n<<"\n";
	}else{
		cout<<(cnt/n)+1<<" ";
		if(((cnt/n)+1)%2==0) cout<<n-(cnt%n)+1<<"\n";
		else cout<<cnt%n<<"\n";
	}
	return 0;
}
