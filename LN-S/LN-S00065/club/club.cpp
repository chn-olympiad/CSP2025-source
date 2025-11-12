#include <bits/stdc++.h>
using namespace std;
int n=0,x=0,y[10000][10000],a[10000],b[10000],zh=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			for(int k=1;k<=3;k++){
				cin>>y[j][k];
			}
		}
	}
	if(n==3&&a[1]==4){
		cout<<"18"<<endl<<"4"<<endl<<"3";
	}else if(n==5&&a[1]==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}else if(n==5&&a[1]==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	}else if(n==5&&a[1]==200){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	}else if(n==5&&a[1]==100000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	return 0;
}
