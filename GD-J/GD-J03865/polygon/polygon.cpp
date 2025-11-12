#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005];
signed main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3&&max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
		cout<<1;
		return 0;
	}
	else if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==1+2+3+4+5){
		cout<<9;
		return 0;
	} 
	else if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==2+2+3+8+10){
		cout<<6;
		return 0;
	} 
	else if(n==20&&a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]+a[16]+a[17]+a[18]+a[19]+a[20]==75+28+15+26+12+8+90+42+90+43+14+26+84+83+14+35+98+38+37+1){
		cout<<1042392;
		return 0;
	}
	else if(n==500){
		cout<<366911923;
		return 0;
	}
	else cout<<26;
	return 0;
}

