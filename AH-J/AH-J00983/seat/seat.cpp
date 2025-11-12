#include <bits/stdc++.h>
using namespace std;
int n,m;
int s;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	if(s%n==0){
		cout<<s/n<<" ";
		if(s/n%2==0)cout<<1;
		if(s/n%2==1)cout<<m;
	}
	else {
		cout<<s/n+1<<" ";
		if((s/n+1)%2==0)cout<<n-(s%n)+1;
		else cout<<s%n;
	}
	return 0;
}
