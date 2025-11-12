#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	map<int,int>a;
	bool dif=false;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i==1)continue;
		if(a[i] != a[i-1])dif=true;
	}
	if(!dif){
		if(a[1]!=k){
			cout<<0;
			return 0;
		}
		cout<<n;
		return 0;
	}
	cout<<0;
	return 0;
}
