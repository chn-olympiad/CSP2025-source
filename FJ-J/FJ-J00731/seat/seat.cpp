#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[10086];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
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
			x=i;
			break;
		}
	}
	int ansx=0,ansy=0;
	if(x%n==0){
		ansx=x/n;
		if(ansx%2==1){
			ansy=n;
		}
		else{
			ansy=1;
		}
	}
	else{
		ansx=x/n+1;
		if(ansx%2==1){
			ansy=x%n;
		}
		else{
			ansy=n-x%n+1;
		}
	}
	cout<<ansx<<" "<<ansy; 
	return 0;
}
