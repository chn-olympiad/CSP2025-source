#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N];
int main(){
	//freopen("seat2.in","r",stdin);
	//freopen("seat2.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=m*n;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	//cout<<p<<endl;
	int u=p/n;
	if(p%n!=0){
		cout<<p/n+1<<" ";
		u=p/n+1;
	}
	else{
		cout<<p/n<<" ";
		u=p/n;
	}
	if(u%2==1){
		if(p%n==0) cout<<n;
		else cout<<p%n;
	}
	else{
		if(p%n==0) cout<<1;
		else cout<<n-p%n+1;
	}
	return 0;
}
