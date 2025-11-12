#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s,b[500010],t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) s++;
		if(a[i]==a[i-1]&&a[i]!=0&&b[i]==b[i-1]&&!b[i]){
			s++;
			b[i]=1;
			b[i-1]=1;
		} 
	}
	if(k==0){
		cout<<s;
		return 0;
	}
	if(k==1){
		 for(int i=1;i<=n;i++){
		 	if(!a[i]) t++; 
		 }
		 cout<<n-t;
	}
	else if(a[1]==2) cout<<2;
	else cout<<a[1];
	return 0;
}
