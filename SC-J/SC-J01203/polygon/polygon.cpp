#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n<0) cout<<"0";
	if(n==1) cout<<"1";
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		a.push_back(t);	
	} 
}
