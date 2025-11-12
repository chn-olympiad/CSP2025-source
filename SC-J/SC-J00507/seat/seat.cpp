#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int stu=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==stu){
			id=i;
			break;
		}
//		cout<<a[i]<<" ";
	}
//	cout<<id;
	if(id%n==0){
		if((id/n)%2==0){
			cout<<id/n<<" "<<1;
		}else cout<<id/n<<" "<<n;
	}else{
		if((id/n)%2==0){
			cout<<id/n+1<<" "<<id%n;
		}else cout<<id/n+1<<" "<<n-(id%n)+1;
	}
	return 0;
} 