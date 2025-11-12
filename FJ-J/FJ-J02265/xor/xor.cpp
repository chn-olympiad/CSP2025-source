#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,ans,sum,a[N],b[N],f[N];
int jq(long long x,long long y){
	if(x==0){
		return y;
	}
	if(y==0){
		return x;
	}
	string str1="",str2="",str="";
	long long len,len1=0,len2=0,jc=1,s=0;
	while(x>=jc){
		len1++;jc*=2;
	}
	jc=1;
	while(y>=jc){
		len2++;jc*=2;
	}
	len=max(len1,len2);
	for(long long i=0;i<len;i++){
		long long tem=pow(2,len-1-i);
		if(x>=tem){
			str1[i]='1';x-=tem;
		}
		else str1[i]='0';
		if(y>=tem){
			str2[i]='1';y-=tem;
		}
		else str2[i]='0';
	}
	for(long long i=0;i<len;i++){
		if(str1[i]==str2[i])str[i]='0';
		else str[i]='1';
	}
	for(long long i=0;i<len;i++){
		long long tem=pow(2,len-1-i);
		s+=(str[i]-'0')*tem;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);b[i]=jq(b[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(jq(b[i],b[j-1])==k){
				f[i]=max(f[i],f[j-1]+1);
			}
		}
	}
	cout<<f[n];
	return 0;
} 
