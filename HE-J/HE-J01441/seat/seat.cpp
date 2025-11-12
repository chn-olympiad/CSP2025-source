#include<bits/stdc++.h> 
using namespace std;
int n,m,a[20][20],b,ans,ai=1,ay=1;
int main(){
	freopin("seat.in","r",stdin);
	freopin("seat.out","w",stdout);
	//cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b=a[1][1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b<a[i][j])ans++;
		}
	}
	for(int i=1;i<=ans;i++){
		if(ay<m&&ai%2==1){
			ay++;
			continue;
		}
		else if(ay==1){
			ai++;
			continue;
		}
		else if(ai%2==0){
			ay--;
			continue;
		}
		else if(ay==m){
			ai++;
			continue;
		}
	}
	cout<<ai<<" "<<ay;
	return 0;
}
