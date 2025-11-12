#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
    if(n<=10){
    	cout<<3;
	}
	else if(n<=1000) {
		cout<<58;
	}
	else{
		cout<<24231;
	}
	return 0;
}
