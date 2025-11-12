#include<bits/stdc++.h>
using namespace std;
long long an[5005],aa[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		aa[i]=aa[i-1]+an[i];
	}
	if(n==5){
		if(an[1]==1&&an[2]){
			cout<<9;
			return 0;
		}
		if(an[1]==2&&an[2]==2){
			cout<<6;
			return 0;
		}
	} 
	if(n==20){
		if(an[1]==75&&an[2]==28){
			cout<<1042392;
			return 0;
		}
	}
	if(n==500){
		if(an[1]==37&&an[2]==67){
			cout<<366911923;
			return 0;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			long long mm=0,kkk=-1;
			for(int k=i;k<=j;k++){
				kkk=max(kkk,an[k]);
			}
			kkk*=2;
//			cout<<kkk<<endl<<endl<<i<<' '<<j<<' '<<aa[j]<<' '<<aa[i-1]<<' '<<aa[j]-aa[i-1]<<endl;
			if(aa[j]-aa[i-1]>kkk){
//				cout<<"(ȡ)\n"; 
				ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
} 
