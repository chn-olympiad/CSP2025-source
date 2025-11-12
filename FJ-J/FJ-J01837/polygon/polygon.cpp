#include<bits/stdc++.h>
using namespace std;
int n,k,p[500001],y,f,w[5001],ro[5001],iu[5001],wp,r,e;
long long ans,q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int d=max(a,max(b,c));
		if(a+b+c>d*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=0;i<n;i++){
			cin>>p[i];
			w[p[i]]++;
			max(r,p[i]);
			if(w[p[i]]==1){
				wp++;
			}
			if(p[i]!=1){
				 f=1;
			}
		}
		if(f==0){
			int x=n-2;
			for(int i=n-1;i>1;i--){
				q+=(n-i)*x;
				x--;
			}
			cout<<q%998244353; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
