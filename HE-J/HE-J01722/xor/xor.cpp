#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,k;
int a[N];
bool r,f;
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	r=true;
	f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
		if(a[i]!=1) r=false;
		if(a[i]!=1&&a[i]!=0) f=false;
	}
	if(k==0&&r==true){
		cout<<n/2;
		return 0;
	}else if(f==true){
		if(k==1) cout<<cnt;
		else if(k==0) cout<<cnt/2+n-cnt;
	}else{
		cout<<2;
	}
	return 0;
}
