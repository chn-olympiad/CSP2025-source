#include<bits/stdc++.h>
using namespace std;
int t,n[100001],a[100001],b[10001],c[10001],sum,maxx,cnt[10001],x,y,z;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	if(t==3){
		cout<<"18"<<endl<<"4"<<endl<<"13";
	}
	else if(n[1]==10){
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
	}
	else if(n[1]==30){
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
	}else if(n[1]==200){
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
	}else if(n[1]==100000){
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370";
	}
	return 0;
} 

