#include <bits/stdc++.h>
using namespace std;
long long n,k,f[500005];
struct node{
	long long a;
	int b;
}s[500005]; 
bool cmp(node x,node y){
	return x.a<x.b;
}
int find_(long long t){
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(s[mid].a>t) r=mid;
		else l=mid;
	}
	if(l==t) return s[l].b;
	else return 0;
}
int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&f[i]);
		f[i]=f[i] xor f[i-1];
		s[i].a=f[i],s[i].b=i;
	}
	sort(s,s+1+n,cmp);
	long long right=0,max1=0;
	for(int i=1;i<=n;i++){
		long long p=f[i] xor k;
		long long ans=find_(p);
		if(f[i]==k&&right==0){
			max1++;
			right = i;
		}
		else if(ans&&ans>=right&&ans<=i-1){
			max1++;
			right = i;
		}
	}
	cout<<max1;
	
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
