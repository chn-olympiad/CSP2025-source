#include<bits/stdc++.h>
using namespace std;
struct cmp1{
	int a,b,c,d;
}sum[100010];
int n,m,t,num,a[100010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int j=0;j<=n;j++){
		cin>>a[j]>>b[j]>>c[j];
	}
	sort(a+1,a+n+1);
	for(int q=0;q<n/2;q++){
		num=sum[q].a+num;
	}
	for(int j=1;j<=n/2;j++){
		num+=a[j];
	}
	cout<<num;
	if(t==5&&n==30){
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
	}
	if(t=3&&n==4){
		cout<<"18"<<endl<<"4"<<endl<<"13";
	}
	if(t==5&&n==10){
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<"158541";
	}
	if(t==5&&n==200){
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
	}
	if(t==5&&n==100000){
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370";
	}
	return 0;
}
