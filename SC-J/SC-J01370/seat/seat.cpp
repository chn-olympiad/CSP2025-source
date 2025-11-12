#include<bits/stdc++.h>
using namespace std;
int s[110],k[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,c=0,p=0,g=0,f=0,d=0;
	cin>>n>>m;
	p=n*m;
	cin>>c;
	s[1]=c;
	k[1]=1;
	for(int i=2;i<=p;i++){
		cin>>s[i];
		k[i]=0;
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p;j++){
			if(s[j]<s[j+1]){
				swap(s[j],s[j+1]);
				swap(k[j],k[j+1]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		if(k[i]==1){
			g=i;
			break;
		}
	}
	if(g%n==0){
		f=g/n;
		if(g%(2*n)==0){
			d=1;
		}else{
			d=n;
		}
	}else{
		f=g/n+1;
		if((g/n)%2==0){
			d=g%n;
		}else{
			d=n-g%n;
		}
	}
	cout<<f<<" "<<d;
	return 0;
}