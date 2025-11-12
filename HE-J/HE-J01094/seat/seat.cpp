#include<bits/stdc++.h>
using namespace std;
int n,m,k,ming=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1,x;i<n*m;i++){
		cin>>x;
		if(x>k){
			ming++;
		}
	}
	int lie=(ming-1)/n+1;
	int hang=ming%n;
	if(!hang){
		hang=n;
	}
	if(lie%2==0){
		hang=n-hang+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
