#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,q,s=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+m*n);
	for(int i=m*n;i>=1;i--){
		if(a[i]==p){
			q=n*m-i+1;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s++;
				if(s==q)cout<<i<<" "<<j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s++;
				if(s==q)cout<<i<<" "<<j;
			}
		}
	}
 	return 0;
}
