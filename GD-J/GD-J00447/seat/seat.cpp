#include <bits/stdc++.h>
using namespace std;
int x,y;
int n[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	int s=x*y;
	for(int i=1;i<=s;i++) cin>>n[i];
	int mc=1;
	for(int i=2;i<=s;i++){
		if(n[i]>n[1]) mc++;
	}
	int mqx=0,mqy=1,mqs=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			mqs++;
			if(mqy%2==1) mqx++;
			else mqx--;
			if(mqx==0){
				mqy++;
				mqx=1;
			}
			else if(mqx==x+1){
				mqy++;
				mqx=x;
			}
			if(mqs==mc){
				cout<<mqy<<" "<<mqx<<endl;
				break;
			}
		}
	}
	return 0;
}
//100pts
