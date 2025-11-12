#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
int n,m; cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int temp=a[1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp) cout<<1<<" "<<i;
	}
	return 0;
}
