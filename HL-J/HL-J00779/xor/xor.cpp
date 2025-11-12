#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],wh=1,s=0;
int ed(int a,int b){
	int g[1000]={},h[1000]={},g1=0,h1=0,c[1000],s,w=1;
	while(a>0){
		 g[g1++]=a%2;
		 a/=2;
	}
	while(b>0){
		 h[h1++]=b%2;
		 b/=2;
	}
	for(int i=0;i<max(g1,h1);i++){
		if(g[i]==h[i]){
			c[i]=0;
		}else{
			c[i]=1;
		}
	}
	for(int i=0;i<max(g1,h1);i++){
		s+=c[i]*w;
		w*=2;
	}
	return s;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int g=a[i];
		if(a[i]==k){
			s++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			g=ed(g,a[j]);
			if(g==k){
				s++;
				i+=wh;
				break;
			}
			wh++;
		}
	}
	cout<<s;	
}
