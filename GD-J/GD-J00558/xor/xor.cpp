#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[500001];
int yh(int a,int b){
	if(a==0) return b;
	int m_=max(a,b);
	int n_=a&b;
	int p=0;
	while(m_) {
		m_/=2;
		p++;
	}
	int k=pow(2,p-1),ans=0;
	for(int o=p;o>=1;o--){
		if(n_>=k){
			n_-=k;
		}else{
			ans+=k;
		}
		k/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int cnt=0,u=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j>u){
				int g=0;
			    for(int k=j;k<=i;k++){
				    g=yh(g,v[k]);
			    }
			    if(g==m){
				    u=i;
				    cnt++;
			    }
			}
		}
	}
	cout<<cnt;
	return 0;
} 
