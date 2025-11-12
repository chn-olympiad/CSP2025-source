#include<bits/stdc++.h>
using namespace std;
int k,n,ma,p,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1){
			ma=x;
		}
		else{
			if(x>ma){
				p++;
			}
		}
	}
	p++;
	int lie=(p+n-1)/n,hang=p%n;
	cout<<lie<<" ";
	if(hang==0){
		cout<<n;
	}
	else if(lie%2==1){
		cout<<hang;
	}
	else{
		cout<<n-hang+1;
	}
	return 0;
}
