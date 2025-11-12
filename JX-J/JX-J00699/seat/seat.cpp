#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v(105);
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>v[i];
	}
	int ra=v[0];
	sort(v.begin(),v.end(),cmd);
	int ia=0;
	while(v[ia]!=ra) ia++;
	
	int tn,tm;
	tn=((ia)/(2*n))*2+1;
	tm=(ia%(n*2))+1;
	if(tm>n){
		tm=2*n-tm+1;
		tn=tn+1;
	}
	cout<<tn<<" "<<tm;
	return 0;
}
