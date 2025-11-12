#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],r,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==r){
			cout<<y<<" "<<x;
			break;
		}
		if(y%2==1){
			if(x+1>n){
				y+=1;
			}else{
				x+=1;
			}
		}else if(y%2==0){
			if(x-1<1){
				y+=1;
			}else{
				x-=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
