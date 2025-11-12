#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,lop;
int a[N],z;
bool cmpp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	lop=a[1];
	sort(a+1,a+n*m+1,cmpp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==lop){
			z=i;
			break;
		}
	}
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
//	cout<<endl;
//	cout<<z<<endl;
//	cout<<endl; 
	int l=(z-1)/n+1;
	if(l&1){
		cout<<l<<" "<<z-(l-1)*n;
	}else{
		cout<<l<<" "<<n+1-(z-(l-1)*n);
	}
	return 0;
}
