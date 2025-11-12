#include<bits/stdc++.h>
using namespace std;
long long n,k,a[600005],sum,s;
long long l[600005],r[600005],li,ri;
long long mod[300005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//a[i]^=a[i-1];
	} if(a[1]!=k) l[++li]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k) sum++;
		if(a[i]!=k&&a[i-1]==k&&i!=1) l[++li]=i;
		if(a[i]!=k&&a[i+1]==k&&i!=n) r[++ri]=i;
	} if(a[n]!=k) r[++ri]=n;
	if(k!=0)
	for(int i=1;i<=li;i++){
		for(int j=l[i];j<=r[i];j++){
			s^=a[j];
			if((s==k&&mod[s]==0)||mod[k^s]==1) sum++,mod[k^s]=0;
			mod[s]++; 
			//cout<<sum<<"\n";
		} s=0;
		memset(mod,sizeof(mod),0);
	} cout<<sum;
	return 0;
} 
