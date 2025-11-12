#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ww=0;
long long q(long long a,long long b){
	long long aa[100],bb[100],k=1,kk=1,c[100],s=1,ff=0;
	for(int i=1;i<=20;i++){
		aa[i]=0;
		bb[i]=0;
	}
	while(a){
		aa[k++]=a%2;
		a/=2;
	}
	while(b){
		bb[kk++]=b%2;
		b/=2;
	}
	for(int i=1;i<=20;i++){
		if((aa[i]==1&&bb[i]==0)||(aa[i]==0&&bb[i]==1))c[i]=1;
		else c[i]=0;
	}
	for(int i=1;i<=20;i++){
		if(c[i]==1)ff+=s;
		s*=2;
	}
	return ff;
}
long long kk(long long a,long long b,long long c,long long d){
	if(b<c&&a<b&&c<d&&a<c&&b<d)return 1;
	else return 0;
}
long long quanzhi(long long x,long long y,long long a[]){
	long long s=0;
	for(int i=x;i<=y-1;i++){
		s+=q(a[i],a[i+1]);
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==0)cout<<1;
		else cout<<0;
	}
	else if(n==2){
		if(a[1]==0&&a[2]==0)cout<<2;
		else if((a[1]!=0)||(a[2]!=0))cout<<1;
		else if(a[1]==a[2])cout<<1;
		else cout<<0;
	}
	else{
	for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;j++){
			if(quanzhi(i,j,a)==k&&kk(i,i+k,j,j+k))ww++;
		}
	}
}}
return 0;
}
