#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int maxn = 5e5+10;
long long xoradd[maxn];
bool aa[23];
bool bb[23];
bool cc[23];
bool dd[23];
long long d;
long long ai;
long long ans;
int usedn[maxn];
int uz;
int alen,blen,dlen;
long long xorr(long long a, long long b){
	for(int i = 0;i<23;i++){
		aa[i] = bb[i] = cc[i] = dd[i] =0;
	}
	d=0; 
	long long shengyu;
	shengyu = a;
	int tpp = 1;
	
	while(shengyu != 0){
		aa[tpp] = shengyu%2;
		shengyu /= 2;
		tpp++;
		alen++;
	}
	shengyu = b;
	tpp = 1;
	while(shengyu != 0){
		bb[tpp] = shengyu%2;
		shengyu /= 2;
		tpp++;
		blen++;
	}
	// aa bb fan
	dlen = max(alen,blen);
	for(int i=1;i<=dlen;i++){
		dd[i] = (aa[i]!=bb[i]);
	}
	// dd fan
	long long nowtwopow = 1;
	for(int i=1;i<=dlen;i++){
		d += dd[i] * nowtwopow;
		nowtwopow*=2;
	}
	return d;
	
}
long long xorqjh(int a,int b){
	return xorr(xoradd[a],xoradd[b]);
}
bool notused(int a, int b){
	// a < b
	for(int i = 1;i<=uz;i++){
		if(a<=usedn[i] && b>=usedn[i])return false;//used
	}
	return true;// not used
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>xoradd[1];
	uz=1;
	if(xoradd[1] == k){
		ans++;
		//cout<<"1to1"<<endl;
		usedn[uz++]=1;
	}
	for(int i = 2; i <= n;i++){
		cin>>ai;
		xoradd[i] = xorr(xoradd[i-1],ai);
		if(ai == k){
			ans++;
			//cout<<i<<"to"<<i<<endl;
			usedn[uz++]=i;
			
		}

	}
	if(n==1){
		cout<<ans;
		return 0;
	}
	for(int i = 2;i <= n;i++){//weishu
		for(int j = 1; j<=(n-i+1);j++){
			if(notused(j,j+i) && xorqjh(j-1,j+i) == k){
				ans++;
				//cout<<j<<"to"<<j+i<<endl;
				for(int z = j; z<=j+1; z++) usedn[uz++]=z;
			}
		}
	}
	
	cout<<ans;
	return 0;
	
}
