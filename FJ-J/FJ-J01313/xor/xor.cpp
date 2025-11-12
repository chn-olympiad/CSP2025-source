#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,z,l[500005],r[500005],c;
long long s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	int i=1;
	while(i<=n){
		if(a[i]==k){
			z++;
			i++;
			continue;
		}
		for(int j=i;j<=n;j++)
			if((s[j]^s[i-1])==k){
				l[++c]=i;
				r[c]=j;
				z++;
				i=j;
				break;
			}
		i++;
	}
	cout<<z;
	return 0;
}
