#include<bits/stdc++.h>
using namespace std;
int a [10010][3];
int b [10010]={0};
int a1=0,a2=0,a3=0,a4=0;
int max(int i,int n){
	if(i==0)return 0;
	int m;
	m=a[i][n]+max(i-1,n);
	if(i==1){
	if(a1>i/2){
	a1=0;a2=0;a3=0;
	return 0;
	}else if(a2>i/2){
	a1=0;a2=0;a3=0;
	return 0;
	}else if(a3>i/2){
	a1=0;a2=0;a3=0;
	return 0;
	}else{
	b[a4]=m;
	a4 ++;
	return 0;
	}}
	if(n==1){a1++;}
	if(n==2){a2++;}
	if(n==3){a3++;}
	n--;
	if(n==0)n=3;
	return m;
}
int main(){
	fstream flie;
	freopen("club.in" ,"r",stdin);
	freopen("club.out" ,"w",stdout);
	int f=0,t,m,b1=0,b2=0,b3=0,w,v=3;
	int n;
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		w=n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			cin>>a[i][j];
			
			}
		}
	m=max(n,3);
	for(int w=0;w<=a4;w++){
		if(f<b[w])f=b[w];
	}
	cout<<f<<endl;
	}
	return 0;
}//真不会尽力了 
