#include <bits/stdc++.h>
using namespace std;
int ans=0,n,m,a[100010];
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(m==0){
			if(a[i]==0){
			cout<<1;
			flag=1;
		}
		else if(a[i]==m){
			cout<<2;
			flag=1;
		}
		}
		
	}
	if(flag==0){
		cout<<0;
	}
	return 0;
}
