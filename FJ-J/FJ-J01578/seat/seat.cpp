#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],w;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			w=n*m-i+1;
		}
	}
	if(w%m==1){
	cout<<w/m+1<<" ";
	if((w/m+1)%2==0) cout<<n-w%m+1;
	else if((w/m+1)%2==1) cout<<w%m;
	}
	else cout<<w/m<<" "<<n;
	
	return 0;
}
