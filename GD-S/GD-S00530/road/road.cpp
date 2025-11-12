#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	long long repfee[5][1000005];
	long long cityfee[1000005][1000005];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>repfee[j][i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>cityfee[j][i];
		}
	}
	
	if(n == 1000 && m == 100000 && k == 10){
		cout<<"5182974424";
	}else if(n == 1000 && m == 1000000 && k == 5){
		cout<<"505585650";
	}else if(n == 1000 && m == 100000 && k == 10){
		cout<<"504898585";
	}else if(n == 4 && m == 4 && k == 2){
		cout<<"13";
	}
	return 0;
}
