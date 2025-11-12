#include<bits/stdc++.h>
using namespace std;
int l[5050];
const int mder=998244353;
int deepfor(int kn,int n,int start,int step,int sum,int max){
	int ans=0;
	if(kn==step){
		return 2*max<sum;
	}
	for(int i=start;i<n;i++){
		ans+=deepfor(kn,n,i+1,step+1,sum+l[i],l[i]);
		ans%=mder;
	}return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool ck=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]!=1)ck=0;
	}
	sort(l,l+n);
	int ans=0;
	if(ck&&n>130){//Partsc 20'
		int ckb=1,cks=0;
		for(int i=n;i>=4;i--){
			ckb*=i;
			ckb%=mder;
			cks+=ckb;
			cks%=mder;
		}cout<<cks+1;
		return 0;
	}
	for(int kn=3;kn<=n;kn++){
		ans+=deepfor(kn,n,0,0,0,0);
		ans%=mder;
	}cout<<ans;
}
