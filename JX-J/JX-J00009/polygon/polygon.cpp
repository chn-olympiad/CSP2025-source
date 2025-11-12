#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f1=1;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f1=0;
			}
		
	}
	if(f1==1){
		int s=0;
		for(int i=3;i<=n;i++){
			int s1=1;
			for(int j=n;j>n-i;j--){
				//cout<<j<<' ';
				s1=s1*j%998244353;
			}
			//cout<<s1;
			int s2=1;
			for(int j=1;j<=i;j++){
				s2=s2*j%99824435;
			}
			//cout<<s2;
			s=(s+s1/s2)%998244353;
		}
		cout<<s%998244353;
	}
	return 0;
}
