#include<bits/stdc++.h>
using namespace std;
bool comp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],i,R,Way,x,y;
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m,comp);
	x=1;y=1;Way=1;i=0;
	while(a[i]!=R){
		if(Way==1){
			if(y!=n){
				y+=Way;
			}else{
				x++;Way=-1;
			}
		}else{
			if(y!=1){
				y+=Way;
			}else{
				x++;Way=1;
			}
		}
		i++;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}