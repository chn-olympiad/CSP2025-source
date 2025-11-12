#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int g,t,rk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	g = a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i = 1;i <= n*m;i++){
		if(a[i] == g){
			rk = i;
			break;
		}
	}
//	cout<<rk<<endl;
	t = rk/n;
	if(rk%n == 0){
		printf("%d ",t);
		if(t%2==1){
			cout<<n-(rk%n);
		} else {
			cout<<rk%n+1;
		}
		return 0;
	} else {
		printf("%d ",t+1);
	}
	if(t%2==1){
		cout<<n+1-(rk%n);
	} else {
		cout<<rk%n;
	}
	return 0;
}
