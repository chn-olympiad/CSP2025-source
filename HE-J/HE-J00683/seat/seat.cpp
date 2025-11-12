#include <bits/stdc++.h>
using namespace std;
const int c=15;
int n,m;//n=hang;m=lie;
int lie=0,hang=0;
int b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
	}
	//enter;
	int a=b[1];
	sort(b+1,b+k+1,cmp);
	//sort;
	for(int i=1;i<=k;i++){
		if(b[i]==a){
			a=i;
			break;
		}
	}
	//search;
	if(a%n==0){
		lie=a/n;
	}
	else {
		lie=a/n+1;
	}
	if(lie%2==1){
		if(a%n==0){
			hang=n;
		}
		else{
			hang=a%n; 
		}
	}
	else if(lie%2==0){
		if(a%n==0){
			hang=1;
		}
		else{
			hang=n-(a%n)+1;
		}
	}
	//T
	cout<<lie<<" "<<hang;
	return 0;
}
