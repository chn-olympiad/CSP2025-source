#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[66][66];
int p[666];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>p[i];
	int x=p[1];
	int c=0;
	for(int i=1;i<=n*m;i++){
		if(p[i]>x) c++;
	}
	c++;
	//cout<<c<<endl<<endl;
	if(c%(2*n)==0) cout<<(c/(2*n))*2<<" "<<1;
	else{
		int k=c/(2*n)+1;// qu kuai
		int l=(2*k-2)*n+1;
		//if(k==1) l=1;
		//else l=(2*k-2)*n+1;
		int jl=c-l+1;
		if(jl%n==0){
			if(jl%(2*n)==0) cout<<2*k<<" "<<1;
			else cout<<2*k-1<<" "<<n;
		}
		else{
			int k2=jl/n+1;
			if(k2==1) cout<<2*k-1<<" "<<jl;
			else{
				jl=jl-(jl-n-1)*2-1;
				cout<<2*k<<" "<<jl;
			}
		}
	}
	return 0;
}

