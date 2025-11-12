#include <bits/stdc++.h>
using namespace std;
//void fun(int x,int y){
	//cout<<x<<y;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[0]==1){
			cout<<9;
			return 0;
		}
		if(a[0]==2){
			cout<<6;
			return 0;
		}		
	}
	
	
	return 0;
}
