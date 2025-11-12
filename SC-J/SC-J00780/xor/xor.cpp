#include <bits/stdc++.h>
using namespace std;
long long n,k,a[10000005],s[10000005],w,maxx=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];} 
	for(long long j=1;j<=n;j++){
			if(a[j]==k){
				maxx++;
				w=j;}
		for(long long i=w+1;i<=j;i++){
			if((s[i-1]^s[j])==k){
				maxx++;
				w=i;
				break;}}}	cout<<maxx;
	return 0;} 