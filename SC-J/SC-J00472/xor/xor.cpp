#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	vector<long long>list(a);
	for(int i=0;i<a;i++){
		cin>>list[i];
	}
	cout<<list[0];
	return 0;
} 