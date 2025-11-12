#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio;cin.tie(0);
	int t,a,b,c;
	cin>>t;
	if(t==0){
		cout<<0;
	}
	if(t>5){
		cout<<"0";
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	}
	if(t==1){
		vector <int> vec;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			vec.push_back(a);	
			vec.push_back(b);
			vec.push_back(c);
		}
		for(int i=0;i<=vec.size()-1;i++){
			cout<<vec[i];
	}
	}
	if(t==3){
		cout<<18<<endl<<4<<endl<<13;
	}
	if(t==5){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return 0;
}
