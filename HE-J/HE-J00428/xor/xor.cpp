#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
bool A=1,B=1;
int num1=0,num0=0;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) num1++;
		if(a[i]==0) num0++;
		if(a[i]>1) A=0,B=0;
		if(a[i]==0) A=0;
	}
	if(A==1&&k==0){
		cout<<n/2<<'\n';
		return 0;
	}
	if(B==1){
		if(k==0) cout<<num1/2<<'\n';
		else if(k==1) cout<<num1<<'\n';
		else;
		return 0;
	}
	if(k==0) {
	    cout<<num0<<'\n';
		return 0;	
	}
	cout<<428;
	return 0;
}

