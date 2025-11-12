#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],r;
void s1(int j){
	if(j%m!=0){
		cout<<j/m+1<<" ";
		if((j/m+1)%2==1){
			cout<<j%m;
		}
		else cout<<m-j%m+1;
	}
	else{
		cout<<j/m<<" ";
		if((j/m)%2==1){
			cout<<m;
		}
		else cout<<1;
	} 
}
int main(){
	fronpen("seat.in","r",stdin);
	fronpen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			int j=n*m-i+1;
			s1(j);
		}
	}
	return 0;
}
