#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int a[N];
int n,m,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0])ans++;
	}
	if(ans%(n*2)<n){
		cout<<ans/n+1<<' '<<ans%(n*2)+1;
	}
	else{
		cout<<ans/n+1<<' '<<n*2-ans%(n*2);
	}
	return 0;
}