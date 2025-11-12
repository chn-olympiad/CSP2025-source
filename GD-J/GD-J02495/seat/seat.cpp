#include<bits/stdc++.h>
using namespace std;

int dvab(int a,int b){
	if(a%b==0) return a/b;
	return a/b+1;

}
int mos(int a,int b){
	if(a%b!=0) return a%b;
	return b;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;cin>>n>>m;
	int rs=n*m;
	int aa[105],R,k;
	cin>>R;
	aa[R]++;
	for(int i=2;i<=rs;i++){
		int t;cin>>t;
		aa[t]++;
	}
	for(int i=100;i>=R;i--){
		if(aa[i]!=0){
			k++;
		}
	}
	int cc=dvab(k,m);
	cout<<cc<<' ';
	if(cc%2==0){
		cout<<n-mos(k,n)+1;
	}else{
		cout<<mos(k,n);
	}
}
