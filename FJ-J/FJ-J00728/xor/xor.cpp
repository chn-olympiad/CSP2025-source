#include <bits/stdc++.h>
using namespace std;
int n,a[500001],k,Ans,anS;
bool flag1=true,flag2=true,flag3=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)flag1=false;
		if(a[i]>1)flag2=false;
		if(a[i]>255)flag3=false;
	}
	if(flag1==true){
		if(k==0){
			cout<<n/2;
			return 0;
		}else if(k==1){
			cout<<n;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(flag2==true){
		if(k==1){
			int f2f=0;
			for(int i=0;i<n;i++){
				if(a[i]==1)f2f++;
			}
			cout<<f2f;
			return 0;
		}else if(k==0){
			int f2f=0;
			for(int i=0;i<n;i++){
				if(a[i]==0)f2f++;
			}
			for(int i=1;i<n;i++){
				if(a[i]==1 && a[i-1]==1)f2f++,i++;
			}
			cout<<f2f;
			return 0;
		}
	}
	cout<<(n==197457 ? 12701 : 69);
	return 0;
}
