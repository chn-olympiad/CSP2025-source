#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501],l,k,c[501],h;
string aa;
void dg(int kk,int p){
	if(kk==n){
		if(n-p>=m)k++;
		k%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			if(aa[kk]=='0'||p>=a[i]){
				dg(kk+1,p+1);
			}else{
				dg(kk+1,p);
			}
			c[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m>>aa;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)h++;
	}
	if(n-h<m){
		cout<<0;
		return 0;
	}
	int g=aa.size();
	for(int i=1;i<=g;i++){
		if(aa[i-1]=='0'){
			l=1;
			break;
		}
	}
	if(l==0){
		k=1;
		for(long long i=1;i<=n;i++){
			k*=i;
			k%=998244353;
		}
		cout<<k;
		return 0;
	}
	dg(0,0);
	cout<<k;
	return 0;
}

