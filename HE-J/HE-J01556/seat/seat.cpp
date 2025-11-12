#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10000005];
int d[10000][10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
			cin>>a[i];	
	}
	int c = a[1];
		int b = n*m;
		int t;
	sort(a+1,a+b+1,greater<int>());
	for(int i = 1;i<=n*m;i++){
		if(a[i] == c){
			t = i+1;
			break;
		}
	}
	if(t/m%2==0){
		cout<<ceil(t/m)<<" "<<m-(t%m);
	}
	else{
		cout<<ceil(t/m)<<" "<<t%m;
	}
		
	return 0;
}
