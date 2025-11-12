#include<bits/stdc++.h>
using namespace std;
int n,k,lt[3000005],b[500005],a[500005],d[500005],p[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
		p[i]=(k^b[i]);
	}
	lt[0]=1;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1];
		if(lt[p[i]]) d[i]=max(d[i],d[lt[p[i]]-1]+1);
		lt[b[i]]=i+1;
	} 
	cout<<d[n];
	return 0;
}

