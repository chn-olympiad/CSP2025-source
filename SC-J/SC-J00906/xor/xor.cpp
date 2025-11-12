#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[b[i]]++;
	} 
	for(int i=0;i<=n;i++){
		if(a[i]!=0) c++;
	} 
	if(k==0){
		if(c==1){
			cout<<n/2;
			return 0;
		}else if(c==2){
			s+=a[0];
			for(int i=1;i<=n-1;i++){
				if(b[i]!=0 && b[i]==b[i+1]){
					s++;
					i+=2;
				}
			}
			cout<<s;
			return 0;
		} 
	} 
	if(k==1) cout<<a[1];
	
	return 0;
} 