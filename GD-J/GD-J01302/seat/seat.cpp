#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int scr[102],seat[11][11];
int n,m,r_scr,i,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>scr[i]; 
	}
	r_scr=scr[1];
	sort(scr+1,scr+n*m+1,cmp);
	for(i=1;i<=n*m;i++){
		int h=i%n,l=i/n+1;
		if(h==0)h=n,l--;
		if(l%2==0){
			h=n-h+1; 
		}			
		if(scr[i]==r_scr){
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
} 
