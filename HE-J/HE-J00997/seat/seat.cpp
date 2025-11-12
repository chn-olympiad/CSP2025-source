
//#include<iostream>
//#include<stdio.h>
//#include<bits/stl_algo.h>
#include<bits/stdc++.h>
using namespace std;
int a[300],b,n,w,m,g=1,c[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++) {
		cin>>a[i];
	}
	if(n==1&&m==1) {
		cout<<1<<' '<<1;
		return 0;
	} 
	b=a[1];
	sort(a+1,a+1+q,cmp);
	if(n==1){
		for(int i=1;i<=m;i++){
			if(b==a[i])
			{
				cout<<i<<' '<<1;
				return 0;
			}
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(b==a[i])
			{
				cout<<1<<' '<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				c[i][j]=a[i];
			}
		} 
		else {
			for(int j=n;j>1;j--){
				c[i][j]=a[i];
			}
		}
	} 
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(c[i][j]==b){
					cout<<i<<' '<<j;
					break; 
				} 
			}
		} 
		else {
			for(int j=n;j>1;j--){
				if(c[i][j]==b){
					cout<<i<<' '<<j; 
					break;
				}
			}
		}
	}
//	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
