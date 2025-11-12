#include<bits/stdc++.h>
using namespace std;
long long x[15]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n;
	cin>>n;
	int l=n.length();
	for(int i=0;i<l;i++){
		if(n[i]>='0'&&n[i]<='9'){
			x[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=x[i];j++){
			cout<<i;
		}
	}
	return 0;
}
