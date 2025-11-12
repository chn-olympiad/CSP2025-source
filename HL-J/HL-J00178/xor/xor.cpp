#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],n,k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((i==j)?(a[i]):(s[i]^s[j]))==k){
				sum++;
				i=j;
			}
		}
	}
	cout<<sum;
	return 0;
}
