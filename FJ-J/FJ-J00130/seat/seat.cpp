#include<bits/stdc++.h>
using namespace std;
int n,m,ss,xt;
int a[15][15],b[150];
bool cac(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int ii=1;ii<=(n*m);ii++){
		cin>>b[ii];
	}
	ss=b[1];
	sort(b+1,b+(n*m)+1,cac);
	for(int ii=1;ii<=(n*m);ii++){
		if(b[ii]==ss){
			xt=ii;
		}
	}
	if(n==1){
		cout<<xt<<' '<<1;
	}else if(n==2&&m==2){
		if(xt<=2){
			cout<<1<<' '<<xt;
		}else{
			cout<<2<<' '<<2-(xt-3);
		}
	}else if(m==1){
		cout<<1<<' '<<xt;
	}else if(n==2){
		if((xt/2+xt%2)%2){
			cout<<xt/2+xt%2<<' '<<2-(xt%n);
		}else{
			cout<<xt/2<<' '<<2;
		}	
	}else{
		if(xt<=n){
			cout<<1<<' '<<xt;
		}else{
			if(xt%n==0){
				if((xt/n)%2){
					cout<<(xt/n)<<' '<<n;
				}else{
					cout<<(xt/n)<<' '<<1;
				}
			}else{
				int sum=xt%n;
				if(((xt/n)+1)%2){
					cout<<(xt/n)+1<<' '<<sum;
				}else{
					cout<<(xt/n)+1<<' '<<n-sum+1;
				}
			}
		}
	}
	return 0;
}
