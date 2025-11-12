#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n*m+1]={0};
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	int xw=x[1];
	sort(x,x+n*m+1);
	int l=1;
	for(int i=n*m;i>0;i--){
		if(x[i]==xw){
			break;
		}
		l++;
	}
	if(l<=n) cout<<1<<" "<<l;
	else{
		int h=1;
		h+=l/n;
		if(h%2==1){
			cout<<h<<" "<<l%n;
		}else{
			cout<<h<<" "<<n-l%n+1;
		}
	}
	
	return 0;
}
