#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5100];
bool b[5100];
void tell(){
	int num=0,max=0,tot =0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			num++;
			if(a[i]>max) max=a[i];
			tot+=a[i];
		}
	}
	if(tot>max*2 && num>=3) ans++;
	return;
}
void digui(int p){
	if(p==n){
		b[p]=0; tell();
		b[p]=1; tell();
		return;
	}
	b[p]=0; digui(p+1);
	b[p]=1; digui(p+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool teshu=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) teshu=0;
	}
	if(teshu){
		long long pow=1,anstemp=0;
		for(int i=1;i<=n;i++){
  			pow*=2;
		}
		anstemp=pow-(n*n+n)/2-1;
		cout<<anstemp%998244353;
	}else{
		digui(1);
		cout<<ans%998244353;
	}              
	return 0;
} 
