#include<bits/stdc++.h>
using namespace std;
int a,b[1000],i,l,n,m;
string s;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	a=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(i=1;i<=n;i++){
		if(i%2){
			for(l=1;l<=m;l++){
				if(b[(i-1)*m+l]==a){
					cout<<i<<' '<<l;
				}
			}
		}
		else{
			for(l=m;l>=1;l--){
				if(b[i*m-l+1]==a){
					cout<<i<<' '<<l;
				}
			}
		}
	}
	return 0;
} 
