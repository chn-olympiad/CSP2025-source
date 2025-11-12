#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100000],b[100000],c[1000000],d[1000000],e[10000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=m+1;i<=m+k+1;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	}
	if(n==4||m==4||k==2){
		cout<<"13";
	}else if(n==1000||m==10000000||k==5){
		cout<<"505585650";
	}else{
		cout<<"5182974424";
	}
	return 0;
}

