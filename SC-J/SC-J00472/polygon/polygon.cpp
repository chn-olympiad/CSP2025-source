#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,cnt=0;
	cin>>a;
	vector<long long>list(a);
	for(int i=1;i<=a;i++){
		cin>>list[i];
	}
	cout<<list[a]+list[a-1];
	return 0;
} 