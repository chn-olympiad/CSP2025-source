#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int mu[5001];
int k;
int res=0;
int linshi[5001];
int he;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>mu[i];
		k+=mu[i];
	}
	if(n<3) cout<<0;
	else if(n==3){
		int o=max(mu[0],mu[1]);
		o=max(o,mu[2]);
		he=mu[1]+mu[0]+mu[2];
		if(he>o*2) cout<<1;
		else cout<<0;
	}
	else{
		int r=0;
		int op = 0;
		sort(mu,mu+n);
		for(int i = n-1;i>=2;i--){
			for(int j = i;j>=2;j--){
				for(int l = 0;l+j<n-op;l++){
					for(int p = l;p<l+j;p++){
						he+=mu[p];
					}
					if(he>mu[i]) r++;
					he=0;
				}
			}
			op++;
		}
		cout<<r;
	}
	return 0;
}
