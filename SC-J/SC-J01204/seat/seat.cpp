#include<bits/stdc++.h>
using namespace std;
int a[10005],b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=n*m;
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	int r=a[1],w=0;
	sort(a+1,a+f+1);
	for(int i=1;i<=f;i++){
		if(a[i]==r){
			w=f-i+1;
		}
	}
	//cout<<w;11111111111
	if(w%n==0) cout<<(w/n)<<" ";
	else cout<<(w/n+1)<<" ";
	if(w%(2*n)<=n) {
		if(w%(2*n)==0){
			cout<<1;
		}else cout<<w%(2*n);
	}
	else{
		cout<<2*n-w%(2*n)+1;
	} 
	return 0;
}