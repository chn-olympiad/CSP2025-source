#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],sum,sum2,p[1000],sum3;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int x[n+5][m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=1;i<=n*m;i++){
		p[n*m-i]=a[i];
	}
	for(int i=0;i<n*m;i++){
			if(p[i]==sum){
				sum3=i+1;
			}
		}
	if(n==1){
		for(int i=0;i<n*m;i++){
			if(p[i]==sum){
				
				cout<<1<<' '<<i+1;
			}
		}
	}
	else if(m==1){
		for(int i=0;i<n*m;i++){
			if(p[i]==sum){
				cout<<i+1<<' '<<1;
				
			}
		}
	}
	else if(n==2&&m==2){
		if(sum3==1){
			cout<<1<<' '<<1;
			 
		}
		else if(sum3==2){
			cout<<1<<' '<<2;
			
		}
		else if(sum3==3){
			cout<<2<<' '<<2;
			
		}
		else if(sum3==4){
			cout<<2<<' '<<1;
		}
	} 
	else if(n==2&&m>=2&&m<=10){
		if(sum3==5){
			cout<<1<<' '<<3;
		}
		else if(sum3==6){
			cout<<2<<' '<<3;
		}
		else if(sum3==7){
			cout<<2<<' '<<4;
		}
		else if(sum3==8){
			cout<<1<<' '<<4;
		}
		else if(sum3==9){
			cout<<1<<' '<<5;
		}
		else if(sum3==10){
			cout<<2<<' '<<5;
		}
		else if(sum3==11){
			cout<<2<<' '<<6;
		}
		else if(sum3==12){
			cout<<1<<' '<<6;
		}
		else if(sum3==13){
			cout<<1<<' '<<7;
		}
		else if(sum3==14){
			cout<<2<<' '<<7;
		}
		else if(sum3==15){
			cout<<2<<' '<<8;
		}
		else if(sum3==16){
			cout<<1<<' '<<8;
		}
		else if(sum3==17){
			cout<<1<<' '<<9;
		}
		else if(sum3==18){
			cout<<2<<' '<<9;
		}
		else if(sum3==19){
			cout<<2<<' '<<10;
		}
		else if(sum3==20){
			cout<<1<<' '<<10;
		}
	}
	return 0;
}
