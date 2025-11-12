#include<bits/stdc++.h>
using namespace std;

int n,n0,n1;
long long k;
long long s[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1)n1++;
		if(s[i]==0)n0++;
	}
	if(k==0){
		int q=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0)q++;
		}
		cout<<q;
		return 0;
	}
	if(n1+n0==n){
		int q=0;
		for(int i=1;i<n;i++){
			if(s[i]!=s[i+1]){
				i++;
				q++;
			}
		}
		cout<<q;
		return 0;
	}
	return 0;
}
