#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int s;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(&a[1],&a[n*m],cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
		}
	}
	cout<<(s-1)/n+1<<" ";
	if((s-1)/n%2){
		cout<<n-(s-1)%n;
	}else{
		cout<<(s-1)%n+1;
	}
	return 0;
}
