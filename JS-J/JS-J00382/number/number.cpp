#include <bits/stdc++.h>
using namespace std;
long long num[10]={0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i=0;
	int n=s.size();
	for(;i<n;i++){
		int t=s[i];
		if(48<= t&& t<=57){
			int u=t-48;
			num[u]++;
		}
	}
	int x=9;
	for(;x>=0;x--){
		for(int j=0;j<num[x];j++){
			cout<<x;
		}
	}
	return 0;
}
