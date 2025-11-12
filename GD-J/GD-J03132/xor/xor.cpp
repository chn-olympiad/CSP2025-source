#include<bits/stdc++.h>
using namespace std;
int xn[5001];
bool vis[5001];
int ans=0;
string n10(int a){
	string x,xx;
	int x1=0;
	while(a>0){
		char a1=(a%10+'0');
		x[x1]=a1;
		a/=10;
		x1++;
	}
	for(int i=0;i<x1;i++){
		xx[i]=x[x1-i-1];
	}
	return xx;
}
int xorx(int a,int b){
	string ax=n10(a),bx=n10(b),c;
	int nx;
	if(ax.size()>bx.size()){
		nx=ax.size();
		c=ax;
	}else{
		nx=bx.size();
		c=bx;
	}
	for(int i=0;i<nx;i++){
		if(ax[i]==bx[i]){
			c[i]='1';
		}else{
			c[i]='0';
		}
	}
	int ii=0,ansx=0;
	for(int i=nx-1;i>=0;i--){
		ansx+=(c[i]-'0')*pow(2,ii);
		ii++;
	}
	return ansx;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	int n,k;
	cin>>n;
	int a1;
	for(int i=1;i<=n;i++){
		cin>>a1;
		if(i==1){
			xn[i]=a1;
			continue;
		} 
		xn[i]=xorx(xn[i-1],a1);
	}
	for(int i=2;i<=n;i++){
		for(int ii=1;ii<i;ii++){
			if(vis[ii]){
				continue;
			}
			if(xorx(xn[i],xn[ii])==k){
				ans++;
				for(int j=ii;j<=i;j++){
					vis[j]=1;
				}
				//cout<<i<<" "<<ii<<endl;
				break;
			}
		}
	}
	cout<<ans;
}

