#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],x,num=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
			return 0;
		}
		else cout<<"0";
		return 0;
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	
	for(int i=3;i<=n;i++){
		int c=n,z=1;
		/*for(int q=1;q<=n;q++){
			if(a[z]+a[z+1]+a[z+2]>a[z+2]*2){
				break; 
			}
			else{
				z++;
			}
		}*/
		for(int j=1;j<=n-i+1;j++){
			if(a[z]+a[z+1]+a[c]>2*a[c]){
				break;
			}
			else{
				c--;
			}
			c=c-z+1;
			int y=c-i+1;
		for(int k=1;k<=c-i+1;k++){
			num+=y*k;
			y--;
			}	
		}
	}
	cout<<num;
	return 0;
} 
