#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],p,g;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==p){
			g=i;
		}
	}
	cout<<g/n+1<<" "<<(((g/n)%2==0)?(g%n)+1:n-(g%n));
	return 0;
}
