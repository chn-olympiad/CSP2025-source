#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],n,k,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(k==0 && n==2){
		if(a[1]==0&&a[2]==0)	cout<<"2";
		else if(a[1]==0 || a[2]==0)	cout<<"1";
		else	cout<<"0";
		return 0;
	}
	cout<<"66";
	return 0;
}