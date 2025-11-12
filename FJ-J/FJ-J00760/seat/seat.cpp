#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],x,t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n;i++){
		for(int j=(i&1?1:m);(i&1?j<=m:j);(i&1?j++:j--),t++){
			if(a[t]==x){cout<<i<<" "<<j;return 0;}
		}
	}
	return 0;
} 
