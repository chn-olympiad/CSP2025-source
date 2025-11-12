#include<bits/stdc++.h> 
using namespace std;
string n;
long long qw[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			qw[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=qw[i];j++){
			cout<<i;
		}
	}
	return 0;
}
