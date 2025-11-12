#include<bits/stdc++.h>
using namespace std;
long long xo(long long aoo,long long boo){
	string aa,bb,ansa;
	long long ans=0;
	while(aoo){
		if(aoo%2==1){
			aa+='1';
		}else aa+='0';
		aoo/=2;
	}
	while(boo){
		if(boo%2==1){
			bb+='1';
		}else bb+='0';
		boo/=2;
	}
	int s=max(aa.size(),bb.size());
	for(int i=0;i<s;i++){
		if(aa[i]!='0'&&aa[i]!='1')aa[i]='0';
		if(bb[i]!='0'&&bb[i]!='1')bb[i]='0';
		if(aa[i]!=bb[i]){
			ansa+='1';
		}else ansa+='0';
	}
	for(int i=ansa.size()-1,k=1;i>=0;i--,k*=2){
		ans+=k*int(ansa[i]-'0');
	}
	return ans;
}
int n,k;
long long a[50010];
long long num=0;
bool check(int oo,int pp){
	if(oo==pp){
		if(a[oo]==k){
			a[oo]=-1;
			return 1;
		}else return 0;
	}
	int kl=a[oo];
	for(int i=oo+1;i<=pp;i++){
		if(a[i]==-1)return 0;
		kl=xo(kl,a[i]);
	}
	if(kl==k){
		for(int i=oo;i<=pp;i++){
			a[i]=-1;
		}
		return 1;
	}
	 
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(j-i+1,j)){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

