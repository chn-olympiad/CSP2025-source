#include<bits/stdc++.h>
using namespace std;
bool pd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a[10001],xy=0;
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>a[i];
	}
	xy=a[0];
	sort(a,a+x*y,pd);
	for(int i=0;i<x*y;i++){
		if(a[i]==xy){
			xy=i+1;
			break;
		}
	}
	for(int i=0;i<x;i++){
		if(i/2==0){
			for(int j=0;j<y;j++){
				xy--;
				if(xy==0){
					cout<<i+1<<" "<<j+1;
				}
			}
		}
		else{
			for(int j=y-1;j>=0;j--){
				xy--;
				if(xy==0){
					cout<<i+1<<" "<<j+1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
