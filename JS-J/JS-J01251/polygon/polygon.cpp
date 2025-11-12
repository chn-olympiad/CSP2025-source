#include<bits/stdc++.h>
using namespace std;
unsigned int n,i,j;
unsigned long long w[5005]={0},ans=0;
void p(unsigned int l,unsigned int t,unsigned long long s){
	if(t==i){
		ans+=(s>2*w[l]);
		return;
	}
	for(int pi=l+1;pi-1-t+i<=n;pi++){
		p(pi,t+1,s+w[pi]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+n+1);
	for(i=3;i<=n;i++){
		p(0,0,0);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
