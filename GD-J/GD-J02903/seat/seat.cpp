#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],se,sum,mus;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	se=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==se){
			sum=i/n;
			mus=i%n;
			if(mus>0){cout<<sum+1<<' ';}
			else{cout<<sum<<" ";}
			if(sum%2){
				if(mus==0){cout<<n;}
				else{cout<<n-mus+1;}
			}
			else{
				if(mus==0){cout<<1;}
				else{cout<<mus;}
			}
			break;
		}
	}
	return 0;
}
