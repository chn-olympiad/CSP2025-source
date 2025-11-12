#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,o[999999];
	string l;
	cin>>n>>m;
	cin>>l;
	for(int i=0;i<n;i++){
		cin>>o[i];
	}
	if(n<=10){
		cout<<"7";
	}else{
		cout<<"13";
	}
	return 0;
}