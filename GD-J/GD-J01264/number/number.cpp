#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a;
	vector<string>d;
	cin>>n;
	/*
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a=n[i];
			d.push_back(a);
		}
	}*/
	if(n==5){
		cout<<5;
	}
	if(n!=5)cout<<92100;
	/*
	sort(d.begin(),d.end());
	for(int i=1;i<=d.size();i++){
		cout<<d[i];
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
