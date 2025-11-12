#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int js5(vector<int> a){
	int js=0;
	if(a[0]+a[1]+a[2]+a[3]+a[4]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[2]+a[4]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[3]+a[4]>2*a[0]){
		js++;
	}
	if(a[0]+a[4]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[4]+a[1]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[2]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[3]>2*a[0]){
		js++;
	}if(a[0]+a[1]+a[4]>2*a[0]){
		js++;
	}
	if(a[0]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[1]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[4]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[4]+a[2]>2*a[0]){
		js++;
	}
	if(a[1]+a[2]+a[4]>2*a[0]){
		js++;
	}
	if(a[3]+a[2]+a[4]>2*a[0]){
		js++;
	}
	return js;
}
int js4(vector<int> a){
	int js=0;
	if(a[0]+a[1]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[2]>2*a[0]){
		js++;
	}
	if(a[0]+a[1]+a[3]>2*a[0]){
		js++;
	}
	if(a[0]+a[2]+a[3]>2*a[0]){
		js++;
	}
	if(a[1]+a[2]+a[3]>2*a[0]){
		js++;
	}
	return js;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxg,n;int x;
	long long zs=0;
	cin>>n;
	vector<int> mg;
	for(int i=0;i<n;i++){
		cin>>x;
		mg.push_back(x);	
	}
	sort(mg.begin(),mg.end(),cmp);
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(mg[0]+mg[1]+mg[2]<2*mg[0]){
		cout<<0;
		return 0;	
	}else{
		cout<<1;
		return 0;	
	}	
	}else if(n==4){
		cout<<js4(mg);
	}
	else if(n==5){
		cout<<js5(mg);
	}else{
	cout<<9;
	}
	
	return 0;
} 
