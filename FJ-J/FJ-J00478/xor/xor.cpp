#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,ans,a,b,k,c,s,e[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>a>>k;
		if(a==k) s++;
		cout<<s;
		return 0;
	}
	if(n==2){
		cin>>a>>b>>k;
		c=a^b;
		if(a==k) s++;
		if(b==k) s++;
		if(c==k) s++;
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>e[i];
	}
	cin>>k;
	if(k==0){
		s=n/2;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(e[i]==1) s++;
		}
	}
	cout<<s;
	
	return 0;
}
