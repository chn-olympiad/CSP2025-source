#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],lie,hang;
bool cmp(int a,int b){
	return a>b;
}
void f(int x,int y,int z){
	lie=z/x+1;
	int q=z%x;
	hang=(lie%2)==0? x-q:q+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	int fir=a[0],p=0;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==fir){
			p=i; break;
		}
	}
	f(n,m,p);
	cout<<lie<<' '<<hang;
	return 0;
}
