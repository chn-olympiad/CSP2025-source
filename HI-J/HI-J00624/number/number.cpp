#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,n=0,sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>="0" && s[i]<="9"){
			n[sum]=n[i];
			sum++;
		} 
	}
	for(int i=0;i<sum;i++){
		cout<<n[i];
	}
	return 0;
}

