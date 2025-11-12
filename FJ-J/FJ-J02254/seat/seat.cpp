//C
#include<bits/stdc++.h>
using namespace std;
int a1[105],a[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a1[i];
	int r=a1[1];
	sort(a1+1,a1+1+n*m);
	for(int i=1;i<=n*m;i++){
		a[n*m-i]=a1[i];
	}
	for(int i=1;i<=n*m;i++) 
		if(a[i]==r) r=i;
	int ai,aj=r%n+1;
	ai=(r-r%n)/m;
	ai++;
	if(ai%2) cout<<ai<<' '<<aj;
	else cout<<ai<<' '<<m-aj+1;
	return 0; 
}
//K
//dif:red?
//44min 100pts
