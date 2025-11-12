#include<bits/stdc++.h>
#include<iostream>
using namespace std; 
int n,m,score[110];
int seat[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int people=n*m; 
	for(int i=1;i<=people;i++){
		cin>>score[i];
	} 
	int Rscore=score[1];
	sort(score,score+1+people);
	int c,r;
	for(int i=1;i<=m;i++){
		int awa=0;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				awa++;
				seat[i][j]=score[awa];
				if(score[awa]==Rscore){
					c=i,r=j;
					break;
				} 
			} 
		}else{
			for(int j=n;j>=1;j--){
				awa++;
				seat[i][j]=score[awa];
				if(score[awa]=Rscore){
					c=i,r=j;
					break;
				} 
			} 
		} 
	} 
	cout<<c<<' '<<r;
	//^o^
	return 0;
} 
