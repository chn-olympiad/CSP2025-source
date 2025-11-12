#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cn,s=0,han=1,lie=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cn=a[1];
	for(int i=2;i<=n*m;i++){
		if(cn<a[i]){
			s++;
		}
	}
	while(s--){
//		cout<<han<<' '<<lie<<'\n';
		if(lie%2==1){
			han++;
		}
		else{
			han--;
		}
		if(han==n+1){
			han=n;
			lie++;
		}
		if(han==0){
			han=1;
			lie++;
		}
	}
	cout<<lie<<' '<<han;
	return 0;
}
