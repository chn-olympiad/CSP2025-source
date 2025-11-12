#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,ma=-1,mi=1e7,a[N],s[N];
//sto CCF && KKK
void solveA(){
	if(k==1)
		cout<<n/3;
	if(k>1)
		cout<<0; 
	return ; 
} 
void solveB(){
	if(ma==0)
		cout<<0;
	if(ma==1){
		if(k>1)
			cout<<0;
		else{
			int l=1,r=2,ans=0;
			while(r<=n){
				if((s[l-1]^s[r])==1){
					ans++;
					l=r;
					r++;
				}else{
					if(s[l-1]!=a[l])l++;
					else r++;
				}
			}
			cout<<ans;
		}
	}
	return ;
}
void solveC(){
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
		s[i]=s[i-1]^a[i];
	}
	if(k==0)
		cout<<n;
	else if(mi==ma && ma==1)
		solveA();
	else if(ma<=1)
		solveB();
	else if(ma<=255)
		solveC();
	return 0;
}

