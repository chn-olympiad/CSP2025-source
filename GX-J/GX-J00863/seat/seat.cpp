#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],k;
	cin>>n>>m;
	for(int i=0;i<n*m;++i){
	cin>>a[i];
}
	k=a[0];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(k==a[j]){
				cout<<i+1<<" ";
				if(i%2==1) cout<<j-2;
				else cout<<m-j-2;
return 0;
}
}
}
}
