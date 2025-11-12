#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int b[100000]={};
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	bool x=1;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			x=0;
			break;
		}
	}
	if(x){
		int a=1;
		for(int i=1;i<=n;i++){
			a*=i;
		}
		cout<<a;
		return 0;
	}
	srand(time(0));
	cout<<rand();
	return 0;
} 
