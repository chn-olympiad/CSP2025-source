#include<bits/stdc++.h>
using namespace std;
int n,m;
int ask[200];
bool ae1(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=0;
	for(int i=1;i<=n*m;i++){
		cin>>ask[i];
		if(i==1){
			a=ask[i];
		}
	}
	sort(ask+1,ask+1+n*m,ae1);
	for(int i=1;i<=n*m;i++){
		if(ask[i]==a){
			int c=ceil(i*1.0/n);
			int r=i%n;
			if(r==0){
				r=n;
			}
			if(c%2==0){
				r=n+1-r;
			}
			cout<<c<<' '<<r;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
