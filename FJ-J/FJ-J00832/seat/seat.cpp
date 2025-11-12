#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,temp,srr;
	cin>>n>>m;
	vector<int> sre;
	cin>>temp;
	srr=temp;
	sre.push_back(temp);
	for(int i=n*m-1;i--;){
		cin>>temp;
		sre.push_back(temp);
	}
	sort(sre.begin(),sre.end(),
		[](int a,int b){
			return a>b;
		}
	);
	int post=0;
	for(auto &ec:sre){
		//cout<<"%one ec%="<<ec<<endl;
		if(ec==srr){
			break;
		}
		post++;
	}
	//cout<<"%post%="<<post<<"\n" ;
	int c,r;
	c=post%(2*n);
	//cout<<"%begin c%"<<c<<"\n";
	r=post/(n)+1;
	if(c<n){
		c++;
	}else{
		c=2*n-c;
	}
	//cout<<"%after c%"<<c<<"\n";
	cout<<r<<" "<<c;
}
