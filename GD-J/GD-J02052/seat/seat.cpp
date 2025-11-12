#include<bits/stdc++.h>
using namespace std;
int n,m;
int ar[110],a,pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ar[i];
		if(i==1) a=ar[i];
	}
	sort(ar+1,ar+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(ar[i]==a){
			pos=i;
			break;
		}
	}
	int k;
	if(pos%n==0){
		k=pos/n;
		if(k%2==0) cout<<k<<" "<<1;
		else cout<<k<<" "<<n;
	}
	else{
		k=pos/n+1;
		int ans;
		if(k%2==0){
			cout<<k<<" "<<n-(pos%n)+1;
		}
		else cout<<k<<" "<<(pos%n);
	}
	
	
	
	return 0;
}
