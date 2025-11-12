#include <bits/stdc++.h>
using namespace std;
int n,m,a[205],idx,hang,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int kl=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==kl){
			idx=n*m-i+1;
			break;
		}
	}
	if(idx%n==0){
		lie=idx/n;
		if(lie%2==1){
			hang=n;
			cout<<lie<<" "<<hang;
		}	
		else{
			hang=1;
			cout<<lie<<" "<<hang;
		}
	}
	else{
		lie=idx/n+1;
		if(lie%2==1){
			hang=idx%n;
			cout<<lie<<" "<<hang;
		}
		else{
			hang=1+(lie*n-idx);
			cout<<lie<<" "<<hang;
		}
	}
	return 0;
}
