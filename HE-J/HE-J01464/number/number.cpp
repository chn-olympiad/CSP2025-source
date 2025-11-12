#include<bits/stdc++.h>
using namespace std;
int n[100001];
int nn[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ans=0;
	int p=1;
	cin>>s;
	int a=s.length(number);
	for(int i=0;i<a;i++){
		for(int j=0;j<i;j++){
			if(n[i]<n[i+1]) {
				nn[i]=n[i];
				n[i]=n[i+1];
				n[i]=nn[i];
			}
			if(n[j+1]<n[j+2]){
				nn[j+1]=n[j];
				n[j+1]=n[j+2];
				n[j+1]=nn[j+1];
			}
		} 
	}
	while(a--){
		p*=10;
		if(a=1)break;
	}
	for(int i=0;i<a;i++){
		ans+=n[i]*p;
		p/=10;
	}
	cout<<ans;
	return 0;
}
