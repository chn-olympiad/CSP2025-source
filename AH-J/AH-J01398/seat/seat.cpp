#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,g=0,f=1,p=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	cin>>a[i];
	g=a[1];
	}
	sort(a,a+1);
	for(int i=1;i<=n*m;i++){
	if(g==a[i]){
		f=i;
		if(f>n){
		p++;
		f-=n;
		}
	}
	}
	cout<<f<<" "<<p;
}
