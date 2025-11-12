#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){ 
		if(a[i]==x){
			int lie=(i-1)/n+1,hang;
			cout<<lie<<' ';
			if(lie>1){
				int pm=i-(lie-1)*n;
				if(lie%2==0) hang=n-pm+1;
				else hang=pm;
			}
			else{
				hang=i;
			}
			cout<<hang;
		}
	}
	return 0;
}