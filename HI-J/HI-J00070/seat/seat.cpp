#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]){
			if(y%2==1){
			 	if(x<n){
					x++;
				}
				else{
					y++;
				}
			}
			if(y%2==0){
			 	if(x>1){
					x--;
				}
				else{
					y++;
				}
			}
		}
	}
	cout<<y<<" "<<x;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
