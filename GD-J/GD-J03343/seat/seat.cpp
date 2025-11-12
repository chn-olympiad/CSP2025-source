#include<bits/stdc++.h>
using namespace std;
int a[150];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1],cnt=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr){
			int x=i/n+(i%n==0 ? 0 : 1);
			int y=(x%2==0 ? n-(i%n)+1 : (i%n==0 ? n :i%n));
			cout<<x<<" "<<y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
