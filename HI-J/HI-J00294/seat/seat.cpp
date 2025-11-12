#include <bits/stdc++.h>
using namespace std;
int b[100],a[100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,b;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==b&&a[i]%2==1){
			cout<<i/m<<" "<<i%m+2;
		}else{
			if(a[i]==b&&a[i]%2==0){
				cout<<i/m<<" "<<n-i%m;
			}
		}
	}	
	return 0;
}
