#include<bits/stdc++.h>
using namespace std;
long long dp[500005],n,a[500005],k2;
string b[500005],k,o;
string turn2(int x){
	if(x==0){
		return "0";
	}
	string too;
	while(x>0){
		too=char(x%2+'0')+too;
		x=x/2;
	}
	return too;
}
string xore(string f,string f2){
	string xo;
	int lenf=f.size(),lenf2=f2.size();
	if(lenf>lenf2){
		for(int i=lenf2+1;i<=lenf;i++){
			f2="0"+f2;
		}
	}else if(lenf<lenf2){
		for(int i=lenf+1;i<=lenf2;i++){
			f="0"+f;
		}
	}
	for(int i=0;i<lenf;i++){
		if(f[i]!=f2[i]){
			xo=xo+'1';
		}else{
			xo=xo+'0';
		}
	}
	return xo;
}
int compare(string y1,string y2){
	int leny1=y1.size(),leny2=y2.size();
	if(leny1>leny2){
		for(int i=leny2+1;i<=leny1;i++){
			y2="0"+y2;
		}
	}else if(leny1<leny2){
		for(int i=leny1+1;i<=leny2;i++){
			y1="0"+y1;
		}
	}
	if(y1==y2){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k2);
	k=turn2(k2);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	b[1]=turn2(a[1]);
	for(int l=2;l<=n;l++){
		o=turn2(a[l]);
		b[l]=xore(b[l-1],o);
	}
	dp[1]=compare(k,b[1]);
	for(int i=2;i<=n;i++){
		dp[i]=compare(b[i],k);
		for(int l=1;l<i;l++){
			string camp=xore(b[i],b[l]);
			dp[i]=max(dp[i],dp[l]+compare(camp,k));
		}
	}
	printf("%lld",dp[n]);
	return 0;
}
