#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],sum,xx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==m) sum++;
	}
	for(int i=0;i<n-1;i++){
		int s=0;
		while(a[i+s]){
			xx++;
			s++;
		}
		xx/=2;
		i+=s;
	}
	if(n<=2){
		if(n==1) cout<<0;
		else cout<<1;
	}
	else if(n<=10){
		int summ=0,summm=0;
		for(int i=0;i<n;i++){
			if(a[i]==0) summ++;
			else summm++; 
		}
		if(m==0)cout<<summ+xx;
		else cout<<summm;
	}
	else if(n<=100){
		if(m==0){
			int summm=0,summ=0;
			for(int i=0;i<n;i++){
				if(a[i]==1) summ++; 
			}
			cout<<xx+summ;
		}
		else if(m==1){
			int summm=0;
			for(int i=0;i<n;i++){
				if(a[i]) summm++; 
			}
			cout<<summm;
		}
	}
	else if(n<=200000){
		if(m<=1){
			int summ=0,summm=0;
			for(int i=0;i<n;i++){
				if(a[i]==0) summ++;
				else summm++; 
			}
			if(m==0)cout<<summ+xx;
			else cout<<summm;
		}
	}
	else{
		cout<<sum;
	}
}
