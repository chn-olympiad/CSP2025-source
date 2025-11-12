#include<bits/stdc++.h> 
using namespace std;
int a[1000000];string b[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int o=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)o=1;
	}
	if(o==0){
		cout<<n;return 0;
	}
	for(int i=1;i<=n;i++){
		int q=a[i];
		string ls="";
		while(q){
			ls=char(q%2+48)+ls;
			q=q/2;
		}
		b[i]=ls;
	}
	int k1=k;
	string k11="";
	while(k1){
		k11=char(k1%2+48)+k11;
		k1=k1/2;
	}
	long long r=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			string h=b[i];
			for(int l=i+1;l<=j;l++){
				int maxn=max(h.size(),b[l].size()) ;
				int maxnn=maxn-h.size(),maxnnn=maxn-b[l].size();
				while(maxnn--)h='0'+h;
				while(maxnnn--)b[l]='0'+b[l];
				string ls="";
				for(int m=0;m<maxn;m++){
					ls=ls+char((h[m]!=b[l][m])+48);
				}
				
				h=ls;
			}
			if(h==k11){
				r++;
			}
			
		}
	}
	cout<<r;
	return 0;
}