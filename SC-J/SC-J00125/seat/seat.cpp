#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,a[101];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int p=a[0];
	sort(a,a+n*m,cmp);
	int mub;
	for(int i=0;i<n*m;i++){
		if(a[i]==p){
			mub=i;
		}
	}
	int x=1,y=1;
	for(int i=1;i<=mub;i++){
		if(x%2==1){
			if(y==n){
				x++;
			}else{
				y++;
			}
		}else if(x%2==0){
			if(y==1){
				x++;
			}else{
				y--;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}