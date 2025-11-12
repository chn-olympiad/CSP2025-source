#include<bits/stdc++.h>
using namespace std;
int a[5005],qz[5005],ans,n;
void hdone(){
	for(int mx=3;mx<=n;mx++){//枚举最大值 a[mx]
		for(int l=1;l+2<=mx;l++){//区间[l,r] 
			int bj=0;
			for(int r=l+1;r<mx&&bj==0;r++){
				if(qz[r]-qz[l-1]>a[mx]){
					ans=(ans+mx-r)%998244353;
					bj=1;
				}
			}
		}
	}
	cout<<ans;	
}
void pts(){
	for(int i=3;i<=n;i++){
		ans+=(n-i)*n%998244353;
	} 
	cout<<ans;
}
void nnn(){
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		nnn();
	}else{
		pts();
	}
	return 0;
}
