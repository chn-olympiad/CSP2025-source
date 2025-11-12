#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int grade=1;
	for(int i=0;i<n*m;i++){
		if(a[0]<a[i]){
			grade++;
		}
	}
	int x=(grade-1)/n+1;
	cout<<x<<' ';
	if(x%2==1){
		cout<<grade-n*(x-1);
	}else{
		cout<<n-(grade-n*(x-1))+1;
	}
	return 0;
}
