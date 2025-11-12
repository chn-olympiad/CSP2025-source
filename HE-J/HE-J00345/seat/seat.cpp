#include <bits/stdc++.h>
using namespace std;
const int T=105;
int a[T];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tot=0;
	cin>>n>>m;
	int k=m*n;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<"1"<<" "<<"1";
	}
	int l=a[0];
	sort(a,a+k);
	for(int i=k-1;i>0;i--){
		if(a[i]==l){
			tot=k-i;
		}
	}
	if(m==1&&n!=1){
		cout<<tot<<" "<<"1";
	}
	if(n==1&&m!=1){
		cout<<"1"<<" "<<tot;
	}
	return 0;
}
