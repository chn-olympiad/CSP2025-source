#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1005],r;
	double l=1;
	cin>>n>>m;
	int t=n*m;
	cin>>r;
	for(int i=2;i<=t;i++){
		cin>>a[i];
	}
	for(int i=1;i<=t;i++){
		if(a[i]>r) l++;
	}
	int lie=int((l-1)/(n*1.0)+1);
	int hang=0;
	if(lie%2==0){
		hang=n-(int(l-1)%(n)+1)+1;
	}
	else{
		hang=int(int(l-1)%(n)+1);
	}
	cout<<lie<<" "<<hang;
	return 0;
}
