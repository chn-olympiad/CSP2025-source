#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5010];
	int n,maxn=0,posib;
	bool flag;
	for(int i=0;i<n;i++){
		cin>>a[i];
	
	}
	for(int i=0;i<n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
 	}
	for(int i=0;i<n;i++){
		if(a[i]+a[i+1]+a[i+2]>maxn*2){
			posib++;
		}
		else if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxn*2){
			posib++;
		}	
	}
	cout<<posib;
	return 0;
}
