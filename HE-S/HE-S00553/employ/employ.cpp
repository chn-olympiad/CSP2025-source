#include<iostream>
using namespace std;

int x[500],y[500],z[500];
int w;
int fdsa(int a,int b,int c){
	if(a==c){
		if(b>=w){
			return 1;
		}else{
			return 0;
		}
		
	}else{
		int k=0;
		for(int i=0;i<c;i++){
			if(z[i]==1){
				if(a-b<x[i]&&y[a]==1){
					z[i]=0;
					k+=fdsa(a+1,b+1,c);
					z[i]=1;
				}else{
					z[i]=0;
					k+=fdsa(a+1,b,c);
					z[i]=1;
				}
			}
		}
		return (k%998244353);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int a,b,c,d;
	cin>>a>>w;
	string e;
	cin>>e;
	for(int i=0;i<a;i++){
		cin>>x[i];
		z[i]=1;
	}
	c=e.size();
	for(int i=0;i<c;i++){
		if(e[i]=='1'){
			y[i]=1;
		}
	}
	int ans=0;
	ans=fdsa(0,0,a);
	cout<<ans;
	return 0;
}
