#include <bits/stdc++.h>
using namespace std;
bool wan(int a,int b){
	return a>b;
}
long long n,m,r,k=0,d,l=0;
int x[19][19],y[1008]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>y[i];
	}
	r=y[1];
	sort(y+1,y+n*m+9,wan);//100 99 98 97
	for(int i=1;i<=n*m;i++){
		if(y[i]==r){
			k=i;//2
			break;
		}
	}
	d=k/n;//1
	if(k%n!=0){
		d++;//1
	}
	if(d%2==1){
		cout<<d<<" ";
		if(k%n==0){
			cout<<n;
		}
		else{
			cout<<k%n;
		}
		
	}
	else{
	cout<<d<<" ";
		for(int i=n;i>=1;i--){
			l++;
			if(l==k%n){
				cout<<i;
			}
		}
		
	}

	return 0;
	
}//hhhhhhhhhh
