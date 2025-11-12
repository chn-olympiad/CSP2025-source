#include<bits/stdc++.h>
using namespace std;
int n, k, pianfen_osl;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	vector<int> a(n);
	bool flag1 = true, flag2 = true;
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=false;
			if(a[i]!=0){
				flag2=false;
			}
		}
		if(a[i]==1){
			pianfen_osl++;
		}
	}
	if(flag1){
		cout<<n<<endl;
		return 0;
	}
	if(flag2){
		cout<<pianfen_osl<<endl;
	}
	return 0;
} 
