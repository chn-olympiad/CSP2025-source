#include<bits/stdc++.h>
using namespace std;
int a[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=0 or m<=0){
		cout<<0<<" "<<0;
		return 0;
	}if(n==1 and m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int b[150];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}int l=b[1];
	sort(b+1,b+1+n*m,cmp);
	
	if(n==1 and m>1){
		for(int i=1;i<=m;i++){
			if(b[i]==l){
				cout<<1<<" "<<i;
				}
			}
		}else if(n>1 and m==1){
			for(int i=1;i<=n;i++){
				if(b[i]==l){
					cout<<i<<" "<<1;
					}
				}
		}
	return 0;
}
