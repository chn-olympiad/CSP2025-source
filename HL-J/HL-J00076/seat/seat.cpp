#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int a[200];
int n,m;
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
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			int lie=(i-1)/n;
			int t=i-lie*n;
			int hang=(lie&1)?m-t:t;
			cout<<lie+1<<" "<<hang;
			return 0;
		}
	}
	//cout<<"ERROR:404 NOT FOUND";
	return 0;
}