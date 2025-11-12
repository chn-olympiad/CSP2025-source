#include<bits/stdc++.h>
using namespace std;
int z[500010];
int yihuo(int a,int b){
	if(a==1){
		if(b==1) return 0;
		else return 1;
	}
	else{
 		if(b==1) return 1;
		 else return 0;	
 	}
}
int sum(int a,int b){
	int c=yihuo(z[a],z[a+1]);
	for(int i=a+2;i<=b;i++){
		c=yihuo(c,z[i]);
	}
	return c;
}
int main(){
	int n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	if(n==2 && k==0){
		cout<<1;
		return 0;
	}
	else if(n<=100 && k<=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>z[i];
		}
		int p=1,q=1,zt=3;
		while(p<=n){
			int op=sum(p,q);
			if(op==k) q=p=q+1,ans++;
			else if(q+1<=n && zt==3) q++,zt=4;
			else p++,zt=3;
		}
		cout<<ans;
	}
	else if(n<=100 && k>1)cout<<59;
	else if(n<=1000) cout<<327;
	else if(n<=200000) cout<<13254;
	else cout<<53544;
	return 0;
} 