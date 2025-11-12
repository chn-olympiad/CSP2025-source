#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15];
struct node{
	int x;
	int y;
}id[15][15];
bool cmp(int a,int b){
	if(a<b){
		return b>a;
	}
	return a>b;
}
int main(){
	cin>>n>>m;
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			id[i][j]={i,j};
		}
	}
	
	int num=0;
	int ans=n*m;
	for(int i=1;i<=ans;i++){
		cin>>a[i];
		num=a[1];
	}
	sort(a+1,a+ans+1,cmp);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i*j]==num){
				cout<<id[i][j].x<<" "<<id[i][j].y;
			}
		}
	}
}
