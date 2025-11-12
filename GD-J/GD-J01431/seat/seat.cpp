#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) t=a[i];
	}
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			int x=i/n+(i%n ? 1:0),y=(i%n ? i%n:n);
			if(x%2==0) y=n-y+1;
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
