#include <bits/stdc++.h>
using namespace std;
int a[107];
bool nm(int nm1,int nm2){
	return nm1>nm2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int wc=n*m; 
	int s=0;
	for(int i=0;i<wc;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+wc,nm);
	int x=1,y=1;
	for(int i=0;i<wc;i++){
		if(a[i]==s){
			cout<<x<<" "<<y;
			break;
		}
		if(x%2!=0){
			y++;
			if(y>n){
				y=n;
				x++;
			}
		}else{
			y--;
			if(y==0){
				y=1;
				x++;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
