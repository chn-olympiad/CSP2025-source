#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x = 0;
	if(n==3){
		for(int i = 1;i <= n-2;i++){
			for(int j = i;j <= n-2;j++){
				if(a[i]+a[j+1]>a[j+2]) x++;
			}
		}
	}
	if(n==4){
		for(int i = 1;i <= n-2;i++){
			for(int j = i;j <= n-2;j++){
				if(a[i]+a[j+1]>a[j+2]) x++;
			}
		}
		if(a[1]+a[2]+a[3]>a[4]) x++; 
	}
	if(n==5){
		for(int i = 1;i <= n-2;i++){
			for(int j = i;j <= n-2;++j){
				if(a[i]+a[j+1]>a[j+2]) x++;
			}
		}
		if(a[1]+a[2]+a[3]>a[4]) x++; 
		if(a[1]+a[2]+a[3]>a[5]) x++;
		if(a[1]+a[2]+a[4]>a[5]) x++;
		if(a[1]+a[3]+a[4]>a[5]) x++;
		if(a[2]+a[3]+a[4]>a[5]) x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5]) x++;
	}
	if(n==6){
		for(int i = 1;i <= n-2;i++){
			for(int j = i;j <= n-2;j++){
				if(a[i]+a[j+1]>a[j+2]) x++;
			}
		}
		if(a[1]+a[2]+a[3]>a[4]) x++; 
		if(a[1]+a[2]+a[3]>a[5]) x++;
		if(a[1]+a[2]+a[3]>a[6]) x++;
		if(a[1]+a[3]+a[4]>a[5]) x++;
		if(a[1]+a[3]+a[4]>a[6]) x++;
		if(a[1]+a[3]+a[5]>a[6]) x++;
		if(a[1]+a[4]+a[5]>a[6]) x++;
		if(a[2]+a[3]+a[4]>a[5]) x++;
		if(a[2]+a[3]+a[4]>a[6]) x++;
		if(a[2]+a[3]+a[5]>a[6]) x++;
		if(a[3]+a[4]+a[5]>a[6]) x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5]) x++;
		if(a[1]+a[2]+a[3]+a[5]>a[6]) x++;
		if(a[1]+a[2]+a[4]+a[5]>a[6]) x++;
		if(a[1]+a[3]+a[4]+a[5]>a[6]) x++;
		if(a[2]+a[3]+a[4]+a[5]>a[6]) x++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) x++;
	}
	cout<<x;
	return 0;
}
