#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100];
int t;
int ppp=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		t=a[1];
		if(a[i]>t) ppp++;
	}
	if(ppp==1){
	    cout<<1<<" "<<1;
		return 0;	
	}
	if(ppp==n*m){
		cout<<m<<" "<<n;
		return 0;
	}
	int lie,hang;
	lie=(ppp-1)/n+1;
	int ru=ppp%n;
	if(lie%2!=0){
		if(ru==0){
			hang=n;
		}else{
			hang=ru;
		}
	} else{
		if(ru==0){
			hang=1;
		}else{
			hang=n-ru+1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
