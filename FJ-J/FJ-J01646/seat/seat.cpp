#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r,p,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i>=1;i--){
		p++;
		if(a[i]==r) break;
	}
	if(p%n==0){
		l=p/n;
		if(l%2==1){
			cout<<l<<" "<<n;
		}else{
			cout<<l<<" 1";
		}
	}else{
		l=(p/n)+1;
		h=p%n;
		if(l%2==1){
			cout<<l<<" "<<h;
		}else{
			cout<<l<<" "<<n-h+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
