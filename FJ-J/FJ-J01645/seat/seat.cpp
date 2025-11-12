#include<bits/stdc++.h>
using namespace std;
int n,m,a[1123],sum,x,y,t,num,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		k++;
		//cout<<a[i]<<endl;
		if(a[i]==sum){
			t=k;
		}
	}
	int num=1;
	x=1,y=1;
	//cout<<sum<<" "<<t<<endl;
	for(int i=2;i<=t;i++){
		if(num%2==0){
			if(y==1){
				x++;
				num++;
			}else{
				y--;
			}
		}else{
			if(y==n){
				x++;
				num++;
			}else{
				y++;	
			}
			
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
