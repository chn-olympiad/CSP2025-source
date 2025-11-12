#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],l[500005],f[500005];
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
		if(m[s[i]^k]){
			l[i]=m[s[i]^k]+1;
		}
		else if(s[i]==k){
			l[i]=1;
		}
		m[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(l[i]){
			f[i]=max(f[i-1],f[l[i]-1]+1);
		}
	}
	cout<<f[n];
	return 0;
}