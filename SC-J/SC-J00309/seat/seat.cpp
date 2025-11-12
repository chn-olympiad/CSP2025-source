#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],asd,q,w;
bool we(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	asd=a[1];
	for(int i=2;i<=n*m;i++)	cin>>a[i];
	sort(a+1,a+n*m,we);
	for(int i=1;i<=n*m;i++){
		if(asd==a[i]){
			q=i/(2*n);
			w=i%(2*n);
			q*=2;
			q+=1;
			if(w<=n) cout<<q<<' '<<w;
			else 	cout<<q+1<<' '<<(2*n)-w+1;
		}
	}
	return 0;
}