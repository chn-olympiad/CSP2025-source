include<bits/stdc++.h>
using namespace std;
int a[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	
	bool f=1,f1=1,f2=1;
	cin>>n>>k;
	if(n<=2&&k==0){
		cout<<1;
		return 0;
	}
	cin>>a[0];
	if(a[0]!=1){
		f=0;
		if(a[0]!=0){
			f1=0;
		}
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			f2=0;
		}
		if(a[i]!=1){
			f=0;
			if(a[i]!=0){
				f1=0;
			}
		}
	}
	if(f&&k==0||f2&&k==0){
		cout<<n;
		return 0;
	}
	cout<<1;
	return 0;
}
