#include<bits/stdc++.h>
using namespace std;
void fuck(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return;
}
int n,m,a[1145140],b,i,t,j;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	fuck();
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1,t=0;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=m;j++){
				t++;
				if(a[t]==b){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(j=m;j>=1;j--){
				t++;
				if(a[t]==b){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0; 
}
