#include<bits/stdc++.h>
using namespace std;
long long s[10000];
char a[1000000];
int h[1000000];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1;i++){
		cin>>s[i];
	}
	
	for(int i=1;i<=1000000;i++){
		if(s[i]==0){
			a[i]=s[i];
			n++;
		}
			if(s[i]==1){
			a[i]=s[i];
			n++;
		}
		if(s[i]==2){
			a[i]=s[i];
			n++;
		}
		if(s[i]==3){
			a[i]=s[i];
			n++;
		}
		if(s[i]==4){
			a[i]=s[i];
			n++;
		}
		if(s[i]==5){
			a[i]=s[i];
			n++;
		}
		if(s[i]==6){
			a[i]=s[i];
			n++;
		}
		if(s[i]==8){
			a[i]=s[i];
			n++;
		}
		if(s[i]==9){
			a[i]=s[i];
			n++;
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			h[i]=a[i]+a[j];
		}
	}
	for(int i=2;i<=n+1;i++){
		h[i]=max(h[i-1],h[i]);
		cout<<h[i];
	}
	return 0;
} 
