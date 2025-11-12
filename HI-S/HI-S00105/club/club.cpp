#include<bits/stdc++.h>
#include<cstdio> 
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;






int main(){	
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int a[3]={0,0,0},t,n,cnt=0,c=0,d=0,e=0;
	cin>>t;
	for(int i=1;i<=t;i++){
	
	
	cin>>n;
	for(int j=1;j<=n;j++){
	
		
	for(int k=1;k<=3;k++){
	cin>>a[k];
		
	}
	
	}
	if((a[1]>a[2])&&(a[1]>a[3])&&(c<=(n/2))){
	c+=1;
	cnt+=a[1];
	
	}
 	else if((a[2]>a[1])&&(a[2]>a[3])&&(d<=(n/2))){
	d+=1;
	cnt+=a[2];
	
	}	
	else if((a[3]>a[1])&&(a[3]>a[2])&&(e<=(n/2))){
	e+=1;
	cnt+=a[3];
	
	}
		
	cout<<cnt<<endl;
	cnt=0;
	}	
	
	
	
	
	//todo
	return 0;
}

