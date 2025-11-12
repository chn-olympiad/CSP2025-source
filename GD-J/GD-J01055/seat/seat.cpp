#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int n,m,a,b,id=1,h,l;
int main(){
	op();
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)id++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				id--;
				if(id==0){
					l=i;
					h=j;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				id--;
				if(id==0){
					l=i;
					h=j;
				}
			}
		}
	}
	cout<<l<<" "<<h;
}
