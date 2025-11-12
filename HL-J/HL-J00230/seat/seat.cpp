#include<bits/stdc++.h>
using namespace std;
int cj[105];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int a=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cj[i]==a){
			int c=(i+n-1)/n;
			int s=(i-1)%n+1;
			int r;
			if(c%2==1){
				r=s;
			}
			else{
				r=n-s+1;
			}
			cout<<c<<" "<<r;
		}
	}
	return 0;
}
