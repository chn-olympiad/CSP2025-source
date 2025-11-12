#include<bits/stdc++.h>
using namespace std;

bool cmt(int a,int b){
	return a>b;
}
int n,m,f,c,r,k=1;
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	f=b[1];
	sort(b+1,b+n*m+1,cmt);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				r=m-j+1;
				c=i;
			}
			else{
				c=i;
				r=j;
			}
			if(b[k]==f){
				cout<<c<<' '<<r;
				return 0;
			}
			k++;
		}
	}
	return 0;
}