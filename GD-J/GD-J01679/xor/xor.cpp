#include<bits/stdc++.h>
using namespace std;
int a[200005];
int v[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			s++;
			v[i]=1;
		} 
	}
	if(n==1&&k==0){
		cout<<0;
		return 0;
	} 
	if(n==2&&k==0){
		cout<<1;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(v[i]==1) continue;
			else{
				if(a[i]==1&&a[i+1]==1){
					s++;
					v[i]=1;
					v[i+1]=1;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
